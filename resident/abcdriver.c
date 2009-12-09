// The Atari Lynx audio system has 8 registers per audio
// channel that can be programmed to produce different
// waveforms.

#define STEREO_REG       (*(char *)0xfd50)
#define VOLUME_REG(chan) (*(char *)(0xfd20 + 0 + chan * 8))
#define FEED_REG(chan)   (*(char *)(0xfd20 + 1 + chan * 8))
#define OUT_REG(chan)    (*(char *)(0xfd20 + 2 + chan * 8))
#define SHIFT_REG(chan)  (*(char *)(0xfd20 + 3 + chan * 8))
#define BKUP_REG(chan)   (*(char *)(0xfd20 + 4 + chan * 8))
#define CTLA_REG(chan)   (*(char *)(0xfd20 + 5 + chan * 8))
#define CNT_REG(chan)    (*(char *)(0xfd20 + 6 + chan * 8))
#define CTLB_REG(chan)   (*(char *)(0xfd20 + 7 + chan * 8))

// This table is used to cover the delays needed for 4 octaves
// These values work when the looplen is 2, 4, 8, 16...
static char delays[] = {
	239, // C,
	225, // ^C, _D,
	213, // D,
	201, // ^D, _E,
	190, // E,
	179, // F,
	169, // ^F, _G,
	159, // G,
	151, // ^G, _A,
	142, // A,
	134, // ^A, _B,
	127, // B,
	119, // C
	113, // ^C _D
	106, // D
	100, // ^D _E
	95, // E
	89, // F
	84, // ^F _G
	80, // G
	75, // ^G  _A
	71, // A
	67, // ^A _B
	63, // B
	60, // c
	56, // ^c _d
	53, // d
	50, // ^d _e
	47, // e
	45, // f
	42, // ^f _g
	40, // g
	38, // ^g _a
	36, // a
	34, // ^a _b
	32, // b
	30, // c'
	28, // ^c' _d'
	27, // d'
	25, // ^d' _e'
	24, // e'
	22, // f'
	21, // ^f' _g'
	20, // g'
	19, // ^g' _a'
	18, // a'
	17, // ^a' _b'
	16 // b'
};

#define NR_OF_CHANNELS 4
#define ATTACK_MODE 1
#define HOLD_MODE   2
#define DECAY_MODE  3

static char envelope_mode[NR_OF_CHANNELS];
static char wanted_volume[NR_OF_CHANNELS];
static char wanted_octave[NR_OF_CHANNELS];
static char vol[NR_OF_CHANNELS];
static char attack[NR_OF_CHANNELS];
static char hold[NR_OF_CHANNELS];
static char decay[NR_OF_CHANNELS];
static int duration[NR_OF_CHANNELS];
static int hold_duration[NR_OF_CHANNELS];

static void set_sound_engine(
	char chan,
    int *settings)
{
	int taps, backup;
	/*char octave;*/
    char integrate;

	taps = settings[0];
	backup = settings[1];
    wanted_octave[chan] = settings[2];
	integrate = settings[3];

    VOLUME_REG(chan) = 0;

    STEREO_REG = 0;

    // Disable count
    CTLA_REG(chan) = 0x10;

    // Setup new sound engine
    FEED_REG(chan) = (taps & 0x1f) + ((taps >> 1) & 0xe0);
    BKUP_REG(chan) = 100; // Very high note, hopefully outside of what you hear
    SHIFT_REG(chan) = backup & 0xff;
    CTLB_REG(chan) = (backup >> 4) & 0xf0;
    CTLA_REG(chan) = ((taps & 0x20) << 2) +
	0x18 + // Enable count
	wanted_octave[chan] +
	(integrate << 5);

	// Define the volume envelope
	wanted_volume[chan] = settings[4];
    attack[chan] = settings[5];
    hold[chan] = settings[6];
    decay[chan] = settings[7];
}

// To keep the sounds related to each other you
// have to use the same loop length or a multiple
// of the looplengths.

// Example use 2, 4, 8, 16, 32...
// or 6, 12, 18

#define USE_MULTIPLES_OF_6

#ifdef USE_MULTIPLES_OF_2
// Clean sound
static int loop2_0[] = {
	1, // taps
	1, // backup
	4,      // octave
	1,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	0       // decay
};

// Clean sound 1 oct down from previous
static int loop4_0[] = {
	2, // taps
	6, // backup
	4,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	0       // decay
};
static int loop8_0[] = {
	8, // taps
	120, // backup
	4,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	0       // decay
};

static int loop8_1[] = {
	8, // taps
	105, // backup
	4,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	0       // decay
};

static int loop8_3[] = {
	25, // taps
	177, // backup
	4,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	0       // decay
};
#endif

#ifdef USE_MULTIPLES_OF_6

#define ABC_FAGOT 3
// wooden fagot or similar
static int loop6_0[] = {
	4, // taps
	28, // backup
	3,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	2       // decay
};

#define ABC_FLUTE 1
// more nasal sound, perhaps oboe
static int loop6_4[] = {
	31, // taps
	50, // backup
	2,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	2       // decay
};

#define ABC_CLARINET 2
// a bit higher format added, clarinet
static int loop6_5[] = {
	31, // taps
	19, // backup
	3,      // octave
	0,      // intergrate
	64,     // volume
	127,    // attack
	127,    // hold
	2       // decay
};

#define ABC_DRUMS 4
static int loop18_0[] = {
	1204, // taps
	1204, // backup
	3,      // octave
	0,      // intergrate
	10,     // volume
	127,    // attack
	0,      // hold
	127     // decay
};

void abc_setinstrument(char chan, int instrument)
{
	int *instr;

	switch (instrument) {
	default:
	case ABC_FLUTE:
        instr = loop6_4;
		break;

	case ABC_CLARINET:
        instr = loop6_5;
		break;

	case ABC_FAGOT:
        instr = loop6_0;
		break;

	case ABC_DRUMS:
        instr = loop18_0;
		break;
	}
	set_sound_engine(chan, instr);
}

#endif

void abc_note(char chan, int height, int note_duration)
{
	char tmp, octave;
    tmp = CTLA_REG(chan) & 0xf8;
	octave = wanted_octave[chan];
	while (height >= 0 && octave > 0) {
		octave--;
		height -= 12;
	}
	CTLA_REG(chan) = tmp | octave;
    BKUP_REG(chan) = delays[height + 12]; // Set the timer reload value
    envelope_mode[chan] = ATTACK_MODE;
    duration[chan] = note_duration;
}

void abc_rest(char chan, int note_duration)
{
    envelope_mode[chan] = DECAY_MODE;
    duration[chan] = note_duration;
    VOLUME_REG(chan) = 0;
}

void abc_pause()
{
    VOLUME_REG(0) = 0;
    VOLUME_REG(1) = 0;
    VOLUME_REG(2) = 0;
    VOLUME_REG(3) = 0;
}

void abc_setvolume(char chan, int volume)
{
    wanted_volume[chan] = (char)volume;
    VOLUME_REG(chan) = (char)volume;
}

// This is just a helper function if the Audio hardware cannot
// take care of playing the sound without CPU help.
// If I want to use envelopes for notes I need to call this
// routine once whenever I call the abc_metronome routine.
void abc_sound(void)
{
    char chan;

    for (chan = 0; chan < NR_OF_CHANNELS; chan++) {
		if (duration[chan] > 0)
			duration[chan]--;
		switch (envelope_mode[chan]) {
		case ATTACK_MODE:
			vol[chan] += attack[chan];
			if (vol[chan] >= wanted_volume[chan]) {
				envelope_mode[chan] = HOLD_MODE;
				vol[chan] = wanted_volume[chan];
				if (duration[chan] < hold[chan])
					hold_duration[chan] = duration[chan];
				else
					hold_duration[chan] = hold[chan];
			}
			VOLUME_REG(chan) = vol[chan];
			break;
		case HOLD_MODE:
			if (hold_duration[chan]--) {
				envelope_mode[chan] = DECAY_MODE;
			}
			break;
		default:
		case DECAY_MODE:
			if (vol[chan] > 0 ) {
				if (vol[chan] > decay[chan]) {
					vol[chan] -= decay[chan];
					if (decay[chan] == 0)
						vol[chan]--;
				} else {
					vol[chan] = 0;
				}
				VOLUME_REG(chan) = vol[chan];
			}
			break;
		}
    }
}
