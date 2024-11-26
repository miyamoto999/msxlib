TARGET=test022.com
TARGET2=test022x.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test022.o
OBJS2=test022x.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=1
CFLAGS=+cpm
# CFLAGS=+msx -subtype=msxdos
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET) $(TARGET2)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldoscall

$(TARGET2):$(OBJS2)
	$(LD) -b -o=$(TARGET2) $(ASCONFIGS) -s -m $(OBJS2)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

%.o:%.c
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -c $<

clean:
	rm -rf $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

test022x.o:test022x.asm ../../include/msxlib/asm/msxdos.inc

-include depends
