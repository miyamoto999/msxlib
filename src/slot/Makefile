TARGET=slot.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=msxslot_rdslt.o
CFLAGS_INC=-I../../include
CFLAGS=+msx $(CFLAGS_INC) -O
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS)
	$(LD) -x$(TARGET) $(OBJS)
	cp -p $(TARGET) ../../libs

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -vn -c $<
#	$(CC) $(CFLAGS) -vn -S $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm

depend:
#	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

msxslot_rdslt.o: msxslot_rdslt.asm ../../include/msxlib/asm/msxbios.inc


-include depends
