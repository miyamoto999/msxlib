TARGET=clrrsd.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=clrrsd.o
CFLAGS_INC=-I../../../include -D__MSXDOS__=1
#CFLAGS=+msx -subtype=msxdos
CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../../libs/msxlib.lib ../../../libs/iot.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../../libs -lmsxlib -liot

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -c $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

-include depends
