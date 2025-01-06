TARGET=test012.bin
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test012.o
CFLAGS_INC=-I../../include -D__DSKBAS__=2
# CFLAGS=+msx -subtype=disk
CFLAGS=+msx -subtype=disk -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/dskcall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldskcall

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -c $<
#	$(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -S $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm *.map *.img *.msx

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends
