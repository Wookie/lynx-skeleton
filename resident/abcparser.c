/*
 * abc music parser
 */

// Declare functions in the abc driver
extern void abc_setinstrument(char chan, int instrument);
extern void abc_note(char chan, int height, int note_duration);
extern void abc_rest(char chan, int note_duration);
extern void abc_setvolume(char chan, int volume);

char silence[] = "";

static char note_indexes[] = {
	8, // Ab
    9, // A
    10, // A# Bb
    11, // B
    12, //
    0, // C
    1, // C# Db
    2, // D
    3, // D# Eb
    4, // E
    5, //
    5, // F
    6, // F# Gb
    7, // G
    8, // G#
    20 , // ab
    21 , // a
    22 , // a# bb
    23 , // b
    12, //
    12, // c
    13, // c# db
    14, // d
    15, // d# eb
    16, // e
    17, //
    17, // f
    18, // f# gb
    19, // g
    20  // g#
};

#define NR_OF_CHANNELS 4

static char *score_ptr[NR_OF_CHANNELS];     // Score
static char *section_start[NR_OF_CHANNELS]; // Start ptr of section to repeat
static int repeat_count[NR_OF_CHANNELS];    // Repeat counter
static int tempo[NR_OF_CHANNELS];           // Tempo ticks/note
#define CHANNEL_NOT_IN_USE -1
static int duration[NR_OF_CHANNELS];        // Ticks left before next note
#define NO_NEXT_NOTE 0x8000
#define NEXT_REST 0x8001
static int next_heights[NR_OF_CHANNELS];    // Next note height

/*
 * Parse a single element. The recognized syntax of an element is
 * [^_]character[/][number]
 * If the parsed character is an audible note then *control is 1
 * else *control contains the character we found in the tune stream.
 * The number is between 1..N even if it does not exist.
 */
static char *get_element(
    char *tune,
    char *control,
    int *nr,
    char *fraction,
    int *height
    )
{
    *control = 1;
    *height = 0;  // C is at height 0
    if (*tune == '^') {
		++(*height);
		++tune;
    }
    if (*tune == '_') {
		--(*height);
		++tune;
    }
    if (*tune >= 'A' && *tune <= 'G') {
		*height = note_indexes[*height + (*tune - 'A') * 2 + 1];
		++tune;
		while (*tune == ',') {
			++tune;
			*height -= 12;
		}
    } else {
		if (*tune >= 'a' && *tune <= 'g') {
			*height = note_indexes[*height + (*tune - 'a') * 2 + 15 + 1];
			++tune;
			while (*tune == '\'') {
				++tune;
				*height += 12;
			}
		} else {
			*control = *tune;
			if (*tune)
				++tune;
		}
    }
    if (*fraction = (*tune == '/')) {
		tune++;
    }
    *nr = 0;
    while (*tune >= '0' && *tune <= '9') {
        *nr = 10 * (*nr) + *tune - '0';
		++tune;
    }
    if (!*nr) {
		if (*fraction)
			*nr = 2;
		else
			*nr = 1;
	}
    return tune;
}

static char *get_next_note(char chan, char *tune)
{
    int nr;
    char control;
    char fraction;
    int height;
    char process_attributes;

    if (!*tune) {
		if (duration[chan] != CHANNEL_NOT_IN_USE) {
			abc_rest(chan, 0);
			duration[chan] = CHANNEL_NOT_IN_USE;
		}
		return tune; // There is no tune
	}

    process_attributes = 1;
    while (process_attributes) {
        tune = get_element(tune, &control, &nr, &fraction, &height);
        switch (control) {
        case 0:
			duration[chan] = 1;
			return tune;
        default:
            process_attributes = 0;
	    break;

        case 'V': // Change main volume of instrument
			abc_setvolume(chan, nr);
			break;
        case 'I': // Change instrument
			abc_setinstrument(chan, nr);
			break;
	
		// Codes affecting the score
        case 'T':
			tempo[chan] = nr;
			break;
        case '|':
			if (*tune == ':') {
				tune++;
				// This implementation does not handle nested
				// repeated sections.
				repeat_count[chan] = nr;
				section_start[chan] = tune;
			}
			break;
        case ':':
			// Go back to start of section
			if (repeat_count[chan])
				--repeat_count[chan];
			if (repeat_count[chan])
				tune = section_start[chan];
			break;
		}
    } while (process_attributes);

    switch (control) {
    case 1:
		if (fraction)
            duration[chan] = tempo[chan] / nr;
        else
			duration[chan] = tempo[chan] * nr;
        next_heights[chan] = height;
		break;
    case 'z':
    case 'x':
		if (fraction)
            duration[chan] = tempo[chan] / nr;
        else
			duration[chan] = tempo[chan] * nr;
		next_heights[chan] = NEXT_REST;
		break;
    default:
		next_heights[chan] = NO_NEXT_NOTE;
		break;
    }
    return tune;
}

// abc_metronome controls the tempo of the music.
// It should be called frequently at determined intervals.
// I use 50 Hz.
void abc_metronome(void)
{
    char chan;

	// Parse attribute stuff for all channels
    for (chan = 0; chan < NR_OF_CHANNELS; chan++) {
		if (duration[chan] != CHANNEL_NOT_IN_USE &&
			--duration[chan] <= 0) {
			score_ptr[chan] = get_next_note(chan, score_ptr[chan]);
		} else {
			next_heights[chan] = NO_NEXT_NOTE;
		}
    }
	// Activate the next note for all channels
	// We want to activate the new note at the same time for all
	// channels. That is why this is separated from attribute parsing
    for (chan = 0; chan < NR_OF_CHANNELS; chan++) {
		int height;
		height = next_heights[chan];
		if (height != NO_NEXT_NOTE) {
			if (height == NEXT_REST) {
				abc_rest(chan, duration[chan]);
			} else {
				abc_note(chan, height, duration[chan]);
			}
		}
    }
}

// play tune defined by score in abc-format
void abc_play(char chan, char *score)
{
    score_ptr[chan] = score;
    duration[chan] = 1;
}
