TARGET1=iotputs.com
TARGET2=iotputi.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS1=iotputs.o
OBJS2=iotputi.o
CFLAGS_INC=-I../../../include -D__MSXDOS__=1
CFLAGS=+msx -subtype=msxdos
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET1) $(TARGET2)

$(TARGET1):$(OBJS1) ../../../libs/msxlib.lib ../../../libs/iot.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET1) $(OBJS1) -L../../../libs -lmsxlib -liot

$(TARGET2):$(OBJS2) ../../../libs/msxlib.lib ../../../libs/iot.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET2) $(OBJS2) -L../../../libs -lmsxlib -liot

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O --no-crt -c $<

clean:
	rm -f $(OBJS1) $(TARGET1) $(OBJS2) $(TARGET2) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

-include depends
