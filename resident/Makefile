################ EDIT THESE ########################
# These are the object files we want this makefile to produce
objects= \
	aaresident.o \
	abcdriver.o \
	abcparser.o \
	filedir.o \
	fileexec.o \
	filehelp.o \
	fileload.o \
	irq.o \
	lynx-stdjoy.o \
	lynx-160-102-16.o \
	vbl.o

############### DONT EDIT BELOW THIS ###############  

# We are compiling for Atari Lynx
SYS=lynx

# These are the names of the tools we use
CO=co65
CC=cc65
AS=ca65
AR=ar65
SPRPCK=sprpck
CP=cp
RM=rm
ECHO=echo

# The flag for adding stuff to a library
ARFLAGS=a

# The flags for compiling C-code
CFLAGS=-I . -t $(SYS) --add-source -O -Or -Cl -Os

# Include paths we may need for compilations
ifeq ($(CC65_INC),)
	CC65_INC=/usr/lib/cc65/include
endif
ifeq ($(CC65_ASMINC),)
	CC65_ASMINC="$(CC65_INC)/../asminc"
endif

# Rule for making a *.o file out of a *.c file
%.o: %.c
	$(CC) $(CFLAGS) -o $(patsubst %c, %s, $(notdir $<)) $<
	$(AS) -o $@ $(AFLAGS) $(*).s
	$(RM) $*.s

# Rule for making a *.o file out of a *.s file
%.o: %.s
	$(AS) -t lynx -I $(CC65_ASMINC) -o $@ $(AFLAGS) $<

# Rule for making a *.o file out of a *.bmp file
%.o : %.bmp
	$(SPRPCK) -t6 -p2 $<
	$(ECHO) .global _$* > $*.s
	$(ECHO) .segment \"$(RODATA_SEGMENT)\" >> $*.s
	$(ECHO) _$*: .incbin \"$*.spr\" >> $*.s
	$(AS) -t lynx -o $@ $(AFLAGS) $*.s
	$(RM) $*.s
	$(RM) $*.pal
	$(RM) $*.spr

all: $(objects)

lynx-stdjoy.o:
	$(CP) "$(CC65_INC)/../joy/$*.joy" .
	$(CO) --code-label _lynxjoy $*.joy
	$(AS) -t lynx -o $@ $(AFLAGS) $*.s
	$(RM) $*.joy
	$(RM) $*.s

lynx-160-102-16.o:
	$(CP) "$(CC65_INC)/../tgi/$*.tgi" .
	$(CO) --code-label _lynxtgi $*.tgi
	$(AS) -t lynx -o $@ $(AFLAGS) $*.s
	$(RM) $*.tgi
	$(RM) $*.s

clean :
	$(RM) $(objects)
