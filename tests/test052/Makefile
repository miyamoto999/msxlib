TARGET=TEST052.COM
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test052.o cif_set_reg_workarea.o msxvdp_set_reg.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=1
# CFLAGS=+cpm
CFLAGS=+cpm
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET)

$(TARGET):$(OBJS) ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -ldoscall

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

%.o:%.c
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<
#	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<

msxvdp_set_reg.o:msxvdp_set_reg.asm

msxvdp_set_reg.asm:../../src/vdp/msxvdp_set_reg.asm
	cp -p $< $@
	echo "PUBLIC set_reg_workarea" >> $@

clean:
	rm -rf $(OBJS) $(TARGET) *.c.asm *.map *.img

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:$(TARGET)
#	emmy80 $(TARGET)

-include depends
