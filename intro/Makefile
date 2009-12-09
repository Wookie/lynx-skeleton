################ EDIT THESE ########################

# As we are producing a cart we want to put our code
# in a loadable segment so that we can load it in RAM
# when we need it and throw it away after use.
# Without these defines the code would go into the
# main RAM and stay there forever.
CODE_SEGMENT=INTRO_CODE
DATA_SEGMENT=INTRO_DATA
RODATA_SEGMENT=INTRO_RODATA
BSS_SEGMENT=INTRO_BSS

# These are the object files we want this makefile to produce
objects= \
	austin.o \
	intro.o \
    titlescreen.o

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
SEGMENTS=--code-name $(CODE_SEGMENT) \
	--rodata-name $(RODATA_SEGMENT) \
	--bss-name $(BSS_SEGMENT) \
	--data-name $(DATA_SEGMENT)

# Include paths we may need for compilations
ifeq ($(CC65_INC),)
	CC65_INC=/usr/lib/cc65/include
endif
ifeq ($(CC65_ASMINC),)
	CC65_ASMINC="$(CC65_INC)/../asminc"
endif

# Rule for making a *.o file out of a *.c file
%.o: %.c
	$(CC) $(CFLAGS) $(SEGMENTS) -o $(patsubst %c, %s, $(notdir $<)) $<
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

clean :
	$(RM) $(objects)

