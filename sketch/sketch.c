// A silly application that allows you to draw pixels around the screen.
// Change colors with Fire 2 (in case your driver supports a second fire
// button).
// Keeping Fire pressed works as an eraser.

#include <lynx.h>
#include <6502.h>
#include <conio.h>
#include <joystick.h>
#include <tgi.h>
#include "../resident/resident.h"
#define tgi_flip() tgi_ioctl(1, 0)
#define tgi_setbgcolor(val) tgi_ioctl(2, (unsigned)(val))
// Music stuff
extern void abc_play(char chan, char *score);
extern void abc_metronome(void);
extern void abc_sound(void);
extern void abc_pause(void);
extern char interruptOccurred;
static char lastInterrupt;

static char drawPending;

static void
framesleep(int n)
{
    int i;
    for (i = 0; i < n; i++) {
		while (lastInterrupt == interruptOccurred)
			;
		abc_metronome();
		abc_sound();
		lastInterrupt = interruptOccurred;
	}
}

extern unsigned char drawpage;

int dummy = 1;

int sketch(void)
{
  int x, y, w, h, frame, r;
  unsigned char color, nrofcolors, background, framecolor;
  char *stitle = "Lynx-Sketch";

  framecolor = COLOR_RED;

  background = COLOR_GREY;

  nrofcolors = tgi_getcolorcount();
  w = tgi_getxres();
  h = tgi_getyres();

  // Single display buffer
  tgi_setviewpage(drawpage);
  tgi_setdrawpage(drawpage);

  // Set our default palette to the hardware
  tgi_setpalette(tgi_getdefpalette());

  // Draw an Etch-A-Scetch style background
  tgi_setcolor(framecolor);
  tgi_bar(0, 0, w-1, h-1);
  tgi_setcolor(background);
  frame = h / 8;
  tgi_bar(frame, frame, w-frame-1, h-frame-1);

  // Set our pen to the center
  x = w / 2;
  y = h / 2;
  color = COLOR_BLACK+1;

  tgi_setcolor(background);
  tgi_setbgcolor(0);
  tgi_outtextxy(frame, frame-10, stitle);

  // Start our application
  drawPending = 0;
  while (1) {
    unsigned char eraser;
    unsigned char joy;
    unsigned char oldcolor;
    joy = joy_read(JOY_1);
    if (JOY_BTN_UP(joy)) {
      y--;
      if (y < frame + 1)
	y = frame + 1;
      drawPending = 1;
    }
    if (JOY_BTN_DOWN(joy)) {
      y++;
      if (y > h - frame - 2)
	y = h - frame - 2;
      drawPending = 1;
    }
    if (JOY_BTN_LEFT(joy)) {
      x--;
      if (x < frame + 1)
	x = frame + 1;
      drawPending = 1;
    }
    if (JOY_BTN_RIGHT(joy)) {
      x++;
      if (x > w - frame - 2)
	x = w - frame - 2;
      drawPending = 1;
    }
    if (JOY_BTN_FIRE(joy)) {
      eraser = 1;
      drawPending = 1;
    } else {
      eraser = 0;
    }
    if (JOY_BTN_FIRE2(joy)) {
      drawPending = 1;
      color++;
      if (color > nrofcolors)
          color = 1;
    }
    if (drawPending) {
      if (eraser) {
        tgi_setcolor(background);
        tgi_bar(x-1, y-1, x+1, y+1);
	r--;
      } else {
        tgi_setcolor(color);
        tgi_setpixel(x, y);
      }
      drawPending = 0;
    }
    // Blink cursor
    oldcolor = tgi_getpixel(x, y);
    tgi_setcolor(oldcolor ^ (nrofcolors - 1));
    tgi_setpixel(x, y);
    framesleep(2);
    tgi_setcolor(oldcolor);
    tgi_setpixel(x, y);
    framesleep(2);
    if (kbhit()) {
        switch (cgetc()) {
        case 'F':
            tgi_flip();
            break;
        case 'R':
            drawpage = 1 - drawpage;
            return RESTART_LYNX;
        case '1':
            drawpage = 1 - drawpage;
            return NEXT_APPLICATION;
        case '2':
            drawpage = 1 - drawpage;
            return PREV_APPLICATION;
        }
    }
  }
}
