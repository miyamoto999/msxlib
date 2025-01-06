TARGET=test006.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test006.o ../common/fcomp.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=2
# CFLAGS=+msx -subtype=msxdos2
CFLAGS=+msx -subtype=msxdos2 -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldoscall

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

tests:

-include depends
