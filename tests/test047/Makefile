TARGET=TEST047.COM
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test047.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=1
CFLAGS=+cpm
# CFLAGS=+msx -subtype=msxdos
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldoscall -lm

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

%.o:%.c
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<
#	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<

clean:
	rm -rf $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:$(TARGET)
	emmy80 $(TARGET)

-include depends
