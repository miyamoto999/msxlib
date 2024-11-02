TARGET=vdp.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=msxvdp.o \
	msxvdp_dos_init.o msxvdp_dct_init.o \
	msxvdp_set_palette2.o msxvdp_set_reg.o \
	msxvdp_dos_draw_char.o msxvdp_dct_draw_char.o msxvdp_dos_draw_string.o msxvdp_dct_draw_string.o \
	msxvdp_dos_draw_char16.o msxvdp_dct_draw_char16.o msxvdp_dos_draw_string16.o msxvdp_dct_draw_string16.o \
	msxvdp2.o
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

msxvdp_set_palette2.o: msxvdp_set_palette2.asm ../../include/msxlib/asm/msxwork.inc
msxvdp_set_reg.o: msxvdp_set_reg.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc

msxvdp_dos_draw_char.c:msxvdp_dct_draw_char.c
	../mk_dosversion.sh $< $@

msxvdp_dos_draw_char16.c:msxvdp_dct_draw_char16.c
	../mk_dosversion.sh $< $@

msxvdp_dos_draw_string.c:msxvdp_dct_draw_string.c
	../mk_dosversion.sh $< $@

msxvdp_dos_draw_string16.c:msxvdp_dct_draw_string16.c
	../mk_dosversion.sh $< $@

-include depends
