TARGET=vdp.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
C_SRCS=msxvdp_cmd_wait.c msxvdp_dct_draw_char16.c  msxvdp_dct_draw_string16.c \
		msxvdp_dos_draw_char.c msxvdp_dos_draw_string.c msxvdp_dos_init.c msxvdp.c \
		msxvdp_dct_draw_char.c msxvdp_dct_draw_string.c msxvdp_dct_init.c \
		msxvdp_dos_draw_char16.c msxvdp_dos_draw_string16.c msxvdp_setpage_sc7.c msxvdp2.c
ASM_SRCS=cif_msxvdp_cmd_hmmc1.asm cif_msxvdp_cmd_hmmc2.asm cif_msxvdp_peek.asm	\
		cif_msxvdp_poke.asm cif_msxvdp_read.asm cif_msxvdp_write.asm msxvdp_cmd_hmmc1.asm \
		msxvdp_cmd_hmmc2.asm msxvdp_get_status.asm msxvdp_peek.asm msxvdp_poke.asm \
		msxvdp_read.asm msxvdp_set_palette2.asm msxvdp_set_reg_indirect.asm msxvdp_set_reg.asm \
		msxvdp_set_vram_addr.asm msxvdp_write.asm
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

msxvdp_dos_draw_char.c:msxvdp_dct_draw_char.c
	../../tools/mk_dosversion.sh $< $@

msxvdp_dos_draw_char16.c:msxvdp_dct_draw_char16.c
	../../tools/mk_dosversion.sh $< $@

msxvdp_dos_draw_string.c:msxvdp_dct_draw_string.c
	../../tools/mk_dosversion.sh $< $@

msxvdp_dos_draw_string16.c:msxvdp_dct_draw_string16.c
	../../tools/mk_dosversion.sh $< $@

-include depends
