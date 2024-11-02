TARGET=test014.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test014.o
CFLAGS_INC=-I../../include -D__MSXDOS__=2
# CFLAGS=+msx -subtype=msxdos2
CFLAGS=+msx -subtype=msxdos2 -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/bios.lib ../../libs/doscall.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lbios -ldoscall -lmsxlib

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

-include depends
