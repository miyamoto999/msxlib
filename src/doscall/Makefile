TARGET=doscall.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
EMU_EXP_OBJS=dos_scode.o
OBJS=$(EMU_EXP_OBJS) dos2_create.o dos2_write.o dos2_close.o dos1_fmake.o dos1_setdta.o dos1_wrblk.o dos1_fclose.o \
	dos1_const.o dos1_dirio.o \
	dos2_defab.o dos2_dosver.o dos2_defer.o dos2_parse.o dos2_pfile.o dos1_fopen.o dos1_rdblk.o dos1_conout.o dos2_open.o \
	dos2_read.o dos2_seek.o
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
#	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

dos2_create.o:dos2_create.asm ../../include/msxlib/asm/msxdos.inc
dos2_write.o:dos2_write.asm ../../include/msxlib/asm/msxdos.inc
dos2_clsoe.o:dos2_clsoe.asm ../../include/msxlib/asm/msxdos.inc
dos1_fmake.o:dos1_fmake.asm ../../include/msxlib/asm/msxdos.inc
dos1_setdta.o:dos1_setdta.asm ../../include/msxlib/asm/msxdos.inc
dos1_wrblk.o:dos1_wrblk.asm ../../include/msxlib/asm/msxdos.inc
dos1_fclose.o:dos1_fclose.asm ../../include/msxlib/asm/msxdos.inc
dos1_const.o:dos1_const.asm ../../include/msxlib/asm/msxdos.inc
dos1_dirio.o:dos1_dirio.asm ../../include/msxlib/asm/msxdos.inc
dos2_defab.o:dos2_defab.asm ../../include/msxlib/asm/msxdos.inc
dos2_dosver.o:dos2_dosver.asm ../../include/msxlib/asm/msxdos.inc
dos2_defer.o:dos2_defer.asm ../../include/msxlib/asm/msxdos.inc
dos2_parse.o:dos2_parse.asm ../../include/msxlib/asm/msxdos.inc
dos2_pfile.o:dos2_pfile.asm ../../include/msxlib/asm/msxdos.inc
dos1_fopen.o:dos1_fopen.asm ../../include/msxlib/asm/msxdos.inc
dos1_rdblk.o:dos1_rdblk.asm ../../include/msxlib/asm/msxdos.inc
dos1_conout.o:dos1_conout.asm ../../include/msxlib/asm/msxdos.inc
dos2_open.o:dos2_open.asm ../../include/msxlib/asm/msxdos.inc
dos2_read.o:dos2_read.asm ../../include/msxlib/asm/msxdos.inc
dos2_seek.o:dos2_seek.asm ../../include/msxlib/asm/msxdos.inc

dos_scode.o:dos_scode.asm ../../include/msxlib/asm/msxdos.inc

-include depends
