TARGET=test004.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test004.o
CFLAGS_INC=-I../../include -D__MSXDOS__=2
# CFLAGS=+msx -subtype=msxdos2
CFLAGS=+msx -subtype=msxdos2 -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/iot.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -liot -ldoscall

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends
