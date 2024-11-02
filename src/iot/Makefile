TARGET=iot.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=iot_node_write.o iot_find2.o iot_find1.o iot_geti.o iot_gets.o iot_puti.o iot_puts.o iot.o iot_read.o iot_write.o \
		cif_iot_geti.o cif_iot_gets.o cif_iot_node_write.o cif_iot_puti.o cif_iot_puts.o cif_iot_read.o
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
	$(CC) $(CFLAGS) --no-crt -c $<
#	$(CC) $(CFLAGS) --no-crt -S $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

iot_node_write.o:iot_node_write.asm ../../include/msxlib/asm/iot.inc
iot_geti.o:iot_geti.asm ../../include/msxlib/asm/iot.inc
iot_puti.o:iot_puti.asm ../../include/msxlib/asm/iot.inc
iot_puts.o:iot_puts.asm ../../include/msxlib/asm/iot.inc
iot_read.o:iot_read.asm ../../include/msxlib/asm/iot.inc
iot_gets.o:iot_gets.asm ../../include/msxlib/asm/iot.inc
iot_write.o:iot_write.asm ../../include/msxlib/asm/iot.inc

-include depends
