TARGET=test034.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test034.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=1
# CFLAGS=+cpm
CFLAGS=+msx -subtype=msxdos
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/asmroutine.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS) --no-crt -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -lasmroutine
#	$(AS) -b -L../../libs -lasmroutine -o$(TARGET) $(OBJS)
#	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldoscall

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

%.o:%.c
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<

clean:
	rm -rf $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
#	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends
