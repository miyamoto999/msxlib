TARGET=iot.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
C_SRCS=iot_find1.c iot_find2.c iot_getbcdf.c iot.c net_connect.c net_init.c net_readline.c \
		net_setup.c
ASM_SRCS=cif_iot_geti.asm cif_iot_gets.asm cif_iot_node_write.asm cif_iot_puti.asm \
		cif_iot_puts.asm cif_iot_read.asm iot_geti.asm iot_gets.asm iot_node_write.asm \
		iot_puti.asm iot_puts.asm iot_read.asm iot_write.asm
OBJS=$(patsubst %.c, %.o, $(C_SRCS)) $(patsubst %.asm, %.o, $(ASM_SRCS))
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
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends
	python ../../tools/mkdepasm.py $(CFLAGS_INC) *.asm >> depends

-include depends
