TARGET=bios.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=msxmain_dos_snsmat.o msxmain_dos_kilbuf.o msxmain_dos_chgmod.o \
	msxmain_dos_chgclr.o dos_extrom.o msxsub_dos_iniplt.o msxmain_dos_gtpad.o \
	msxmain_dct_chgclr.o msxmain_dct_chgmod.o msxmain_dct_snsmat.o msxmain_dct_kilbuf.o msxsub_dct_iniplt.o msxmain_dct_gtpad.o \
	msxsub_dct_chgmdp.o msxsub_dos_chgmdp.o msxsub_dos_cls.o msxsub_dct_cls.o \
	msxmain_dos_grpprt.o msxmain_dct_grpprt.o \
	msxsub_dos_redclk.o msxsub_dct_redclk.o msxsub_dos_knjprt.o msxsub_dct_knjprt.o msxsub_dos_setplt.o msxsub_dct_setplt.o \
	msxmain_dct_chput.o msxmain_dos_chput.o msxmain_dct_chget.o msxmain_dos_chget.o
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

dos_extrom.o: dos_extrom.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dct_chgmod.o: msxmain_dct_chgmod.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dct_snsmat.o: msxmain_dct_snsmat.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dct_kilbuf.o: msxmain_dct_kilbuf.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_iniplt.o: msxsub_dct_iniplt.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dct_gtpad.o: msxmain_dct_gtpad.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_chgmdp.o: msxsub_dct_chgmdp.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dos_chgmdp.o: msxsub_dos_chgmdp.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dos_cls.o: msxsub_dos_cls.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_cls.o: msxsub_dct_cls.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dct_chgclr.o: msxmain_dct_chgclr.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dos_chgclr.o: msxmain_dos_chgclr.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dos_grpprt.o: msxmain_dos_grpprt.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dct_grpprt.o: msxmain_dct_grpprt.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dos_redclk.o: msxsub_dos_redclk.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_redclk.o: msxsub_dct_redclk.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dos_chgmod.o: msxmain_dos_chgmod.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dos_gtpad.o: msxmain_dos_gtpad.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dos_kilbuf.o: msxmain_dos_kilbuf.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dos_snsmat.o: msxmain_dos_snsmat.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxsub_dos_iniplt.o: msxsub_dos_iniplt.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dos_knjprt.o: msxsub_dos_knjprt.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_knjprt.o: msxsub_dct_knjprt.asm ../../include/msxlib/asm/msxbios.inc

msxsub_dos_setplt.o: msxsub_dos_setplt.asm ../../include/msxlib/asm/msxbios.inc
msxsub_dct_setplt.o: msxsub_dct_setplt.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dos_chput.o: msxmain_dos_chput.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dct_chput.o: msxmain_dct_chput.asm ../../include/msxlib/asm/msxbios.inc
msxmain_dos_chget.o: msxmain_dos_chget.asm ../../include/msxlib/asm/msxbios.inc ../../include/msxlib/asm/msxwork.inc
msxmain_dct_chget.o: msxmain_dct_chget.asm ../../include/msxlib/asm/msxbios.inc

-include depends
