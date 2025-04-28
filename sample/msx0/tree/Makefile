TARGET=tree.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=tree.o
CFLAGS_INC=-I../../../include -D__MSXDOS__=1
CFLAGS=+msx -subtype=msxdos
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
	# $(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -S -c $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends
