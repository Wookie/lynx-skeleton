#include <lynx.h>
#include <tgi.h>
#include <joystick.h>
#include <conio.h>
#include <6502.h>
#include "../resident/resident.h"

// Music stuff
extern void abc_play(char chan, char *score);
extern void abc_metronome(void);
extern void abc_sound(void);
extern void abc_pause(void);
extern char voice1[];
extern char voice2[];
extern char voice3[];
extern char voice4[];
extern char silence[];

// Graphics driver
extern char lynxtgi[];
#define tgi_sprite(spr) tgi_ioctl(0, (unsigned)(spr))
#define tgi_flip() tgi_ioctl(1, 0)
//#define tgi_setbgcolor(col) tgi_ioctl(2, col)
extern void init_irq(void);
extern void install_irq(unsigned char num, unsigned func );
extern void vbl(void);
#define enable_irq(n)\
  asm(" lda #$80\n"\
      " tsb $fd01+"#n"*4\n")	/* enable interrupt of timer n */
extern char interruptOccurred;
extern unsigned char drawPending;
extern unsigned char drawpage;

// Joypad driver
extern char lynxjoy[];

// Title sprite
extern char *titlescreen;

typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    void *next;
    void *bitmap;
    int posx, posy, sizex, sizey;
    unsigned char palette[8];
} sprite_t;

sprite_t Stitle = {
    0xc0,0x10,0x20,
    0,&titlescreen,
    0,0,0x100,0x100,
    {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef}
};

// Define the palette for the title screen
// I just created some names for the colors so that
// it is easier to fine tune the palette for the
// real Lynx. The order is GREEN BLUE RED
#define C_BLACK			0x000
#define C_BLUE			0x0f0
#define C_RED			0x00f
#define C_GRAY			0x555
#define C_UNDEFINED1	0x44a
#define C_UNDEFINED2	0x4f6
#define C_GREEN			0xf00
#define C_LIGHTBLUE		0x8f8
#define C_ORANGE		0x88f
#define C_CYAN			0xff0
#define C_LIGHTMAGENTA  0x8ff
#define C_UNDEFINED3    0xd74
#define C_DARKFLESH		0xb4b
#define C_FLESH			0xb6f
#define C_YELLOW		0xf0c
#define C_WHITE			0xfff

static char pal[] = {
    C_BLACK >> 8,
    C_BLUE >> 8,
    C_RED >> 8,
    C_GRAY >> 8,
    C_UNDEFINED1 >> 8,
    C_UNDEFINED2 >> 8,
    C_GREEN >> 8,
    C_LIGHTBLUE >> 8,
    C_ORANGE >> 8,
    C_CYAN >> 8,
    C_LIGHTMAGENTA >> 8,
    C_UNDEFINED3 >> 8,
    C_DARKFLESH >> 8,
    C_FLESH >> 8,
    C_YELLOW >> 8,
    C_WHITE >> 8,
    C_BLACK & 0xff,
    C_BLUE & 0xff,
    C_RED & 0xff,
    C_GRAY & 0xff,
    C_UNDEFINED1 & 0xff,
    C_UNDEFINED2 & 0xff,
    C_GREEN & 0xff,
    C_LIGHTBLUE & 0xff,
    C_ORANGE & 0xff,
    C_CYAN & 0xff,
    C_LIGHTMAGENTA & 0xff,
    C_UNDEFINED3 & 0xff,
    C_DARKFLESH & 0xff,
    C_FLESH & 0xff,
    C_YELLOW & 0xff,
    C_WHITE & 0xff};

// Instruments and tempos
#define FLUTE		"I1T8"
#define TRUMPET		"I2T8"
#define TROMBONE	"I3T8"
#define DRUMS		"I4T8"

int intro(void) 
{
	char running, pause, update_needed, lastInterrupt;
	int next_program;

	// Setup instruments for all channels
    abc_play(0, FLUTE);
    abc_play(1, TRUMPET);
    abc_play(2, TROMBONE);
    abc_play(3, DRUMS);
	// Process instrument settings in the driver
    abc_metronome();

	//Start playing the music intro on all channels
    abc_play(0, voice1);
    abc_play(1, voice2);
    abc_play(2, voice3);
    abc_play(3, voice4);

	running = 1;
	pause = 0;
	update_needed = 1;
	lastInterrupt = interruptOccurred;
	tgi_setpalette(pal);
	tgi_sprite(&Stitle);
	drawPending = 1;

    while (running) {
        unsigned char joy;

		// Process key presses
		if (kbhit()) {
			switch (cgetc()) {
			case '1':
			case '2':
			case '3':
			case '?':
				next_program = SKETCH;
				running = 0;
				continue;
			case 'R':
				next_program = RESTART_LYNX;
				running = 0;
				continue;
			case 'F':
				tgi_flip();
				joy_install(&lynxjoy);
				break;
			case 'P':
				pause = 1 - pause;
				if (pause)
					abc_pause();
				break;
			}
		}
		if (pause)
			continue;

		// Gameplay section starts here
		// You should advance the time here
        joy = joy_read(JOY_1);
        if (JOY_BTN_UP(joy)) {
			update_needed = 1;
        }
        if (JOY_BTN_DOWN(joy)) {
			update_needed = 1;
        }
        if (JOY_BTN_LEFT(joy)) {
			update_needed = 1;
        }
        if (JOY_BTN_RIGHT(joy)) {
			update_needed = 1;
        }
        if (JOY_BTN_FIRE(joy)) {
			update_needed = 1;
        }
        if (JOY_BTN_FIRE2(joy)) {
			update_needed = 1;
        }

		// Interrupts occur every 20ms
		// Things like music is updated here.
		// You can also lock your game timing to these
		// interrupts to achieve a constant speed
		if (lastInterrupt != interruptOccurred) {
            abc_metronome();
            abc_sound();
			lastInterrupt = interruptOccurred;
		}

		// Screen updates are done only if the previous buffer
		// is already on screen and there is a reason to create
		// a new image for the user
        if (!drawPending && update_needed) {
			tgi_setpalette(pal);
			tgi_sprite(&Stitle);
			drawPending = 1;
			update_needed = 0;
        }
    }
	// Because the voices are in my "disposable" code segment
	// I have to kill the music before I return to the scheduler
	// otherwise the music could be overloaded with code and that
	// does not sound nice.
    abc_play(0, silence);
    abc_play(1, silence);
    abc_play(2, silence);
    abc_play(3, silence);
    abc_metronome();
    return next_program;
} 

void start_irqs(void)
{
    tgi_install(&lynxtgi); // This will activate the Lynx screen 
    joy_install(&lynxjoy); // This will activate the Lynx screen 
    tgi_setdrawpage(drawpage); // Set page for drawing stuff on. Can be 0 or 1.     tgi_init();
    init_irq();
    //install_uploader(_9600Bd);
    install_irq(2, (int)&vbl);
    enable_irq(2);
    CLI();
}
