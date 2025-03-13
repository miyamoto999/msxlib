TARGET=asmroutine.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=disphex.o dump.o dump2.o out_crlf.o out_spc.o
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

disphex.o:disphex.asm ../../include/msxlib/asm/msxdos.inc
out_crlf.o:out_crlf.asm ../../include/msxlib/asm/msxdos.inc
out_spc.o:out_spc.asm ../../include/msxlib/asm/msxdos.inc

-include depends
