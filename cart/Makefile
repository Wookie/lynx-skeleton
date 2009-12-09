#
# makefile to create a complete Atari Lynx cart using the
# the www.cc65.org compiler
#
# Currently the only user applications are "intro" for the startup
# and "sketch" for a drawing application.
# If you want more loadable modules you need to add them just like
# the "sketch" is created.
# Note: you need to add them to this Makefile, to the directory.s
# and you have to create a new directory for the new module.

################ EDIT THESE ########################

# These are the object files we want this makefile to produce
objects= \
	lnxhdr.o \
	encrypt1024.o \
	directory.o \
	title.o

others = \
	../resident/*.o \
	../intro/*.o \
	../sketch/*.o

target = cart.lnx

############### DONT EDIT BELOW THIS ###############  

# We are compiling for Atari Lynx
SYS=lynx

# These are the names of the tools we use
CL=cl65
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

all: $(target)

$(target) : $(objects) $(others)
	$(CL) -t $(SYS) -o $@ -m lynxcart.map -C lynxcart.cfg $(objects) $(others) lynx.lib 
	$(RM) null

clean :
	$(RM) $(objects)
	$(RM) $(target)
	$(RM) lynxcart.map
