TARGET=doscall.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
EMU_EXP_OBJS=dos_scode.o
OBJS_DOS1=dos1_fmake.o dos1_setdta.o dos1_wrblk.o dos1_fclose.o \
	dos1_const.o dos1_dirio.o \
	dos1_fopen.o dos1_rdblk.o dos1_conout.o \
	dos1_sfirst.o dos1_snext.o dos1_fdel.o dos1_rdseq.o dos1_fren.o \
	dos1_rename.o dos1_login.o dos1_alloc.o dos1_rdrnd.o dos1_remove.o dos1_wrseq.o dos1_wrrnd.o dos1_fsize.o dos1_setrnd.o \
	dos1_wrzer.o dos1_gdate.o dos1_sdate.o dos1_gtime.o dos1_stime.o dos1_term0.o dos1_auxin.o dos1_auxout.o dos1_lstout.o \
	dos1_dirin.o dos1_innoe.o dos1_bufin.o dos1_cpmver.o dos1_dskrst.o dos1_seldsk.o dos1_curdrv.o dos1_verify.o dos1_rdabs.o \
	dos1_wrabs.o
OBJS_DOS2=dos2_create.o dos2_write.o dos2_open.o dos2_close.o \
	dos2_defab.o dos2_dosver.o dos2_defer.o dos2_parse.o dos2_pfile.o \
	dos2_read.o dos2_seek.o dos2_ffirst.o dos2_fnext.o dos2_ioctl.o
OBJS=$(EMU_EXP_OBJS) $(OBJS_DOS1) $(OBJS_DOS2) msxlib_doscall.o
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
dos1_sfirst.o:dos1_sfirst.asm ../../include/msxlib/asm/msxdos.inc
dos1_snext.o:dos1_snext.asm ../../include/msxlib/asm/msxdos.inc
dos2_ffirst.o:dos2_ffirst.asm ../../include/msxlib/asm/msxdos.inc
dos2_fnext.o:dos2_fnext.asm ../../include/msxlib/asm/msxdos.inc
dos1_fdel.o:dos1_fdel.asm ../../include/msxlib/asm/msxdos.inc
dos1_rdseq.o:dos1_rdseq.asm ../../include/msxlib/asm/msxdos.inc
dos1_fren.o:dos1_fren.asm ../../include/msxlib/asm/msxdos.inc
dos1_login.o:dos1_login.asm ../../include/msxlib/asm/msxdos.inc
dos1_alloc.o:dos1_alloc.asm ../../include/msxlib/asm/msxdos.inc
dos1_rdrnd.o:dos1_rdrnd.asm ../../include/msxlib/asm/msxdos.inc
dos1_wrseq.o:dos1_wrseq.asm ../../include/msxlib/asm/msxdos.inc
dos1_wrrnd.o:dos1_wrrnd.asm ../../include/msxlib/asm/msxdos.inc
dos1_fsize.o:dos1_fsize.asm ../../include/msxlib/asm/msxdos.inc
dos1_setrnd.o:dos1_setrnd.asm ../../include/msxlib/asm/msxdos.inc
dos1_wrzer.o:dos1_wrzer.asm ../../include/msxlib/asm/msxdos.inc
dos1_gdate.o:dos1_gdate.asm ../../include/msxlib/asm/msxdos.inc
dos1_sdate.o:dos1_sdate.asm ../../include/msxlib/asm/msxdos.inc
dos1_gtime.o:dos1_gtime.asm ../../include/msxlib/asm/msxdos.inc
dos1_stime.o:dos1_stime.asm ../../include/msxlib/asm/msxdos.inc
dos1_term0.o:dos1_term0.asm ../../include/msxlib/asm/msxdos.inc
dos1_auxin.o:dos1_auxin.asm ../../include/msxlib/asm/msxdos.inc
dos1_auxout.o:dos1_auxout.asm ../../include/msxlib/asm/msxdos.inc
dos1_lstout.o:dos1_lstout.asm ../../include/msxlib/asm/msxdos.inc
dos1_dirin.o:dos1_dirin.asm ../../include/msxlib/asm/msxdos.inc
dos1_innoe.o:dos1_innoe.asm ../../include/msxlib/asm/msxdos.inc
dos1_bufin.o:dos1_bufin.asm ../../include/msxlib/asm/msxdos.inc
dos1_cpmver.o:dos1_cpmver.asm ../../include/msxlib/asm/msxdos.inc
dos1_dskrst.o:dos1_dskrst.asm ../../include/msxlib/asm/msxdos.inc
dos1_seldsk.o:dos1_seldsk.asm ../../include/msxlib/asm/msxdos.inc
dos1_curdrv.o:dos1_curdrv.asm ../../include/msxlib/asm/msxdos.inc
dos1_verify.o:dos1_verify.asm ../../include/msxlib/asm/msxdos.inc
dos1_rdabs.o:dos1_rdabs.asm ../../include/msxlib/asm/msxdos.inc
dos1_wrabs.o:dos1_wrabs.asm ../../include/msxlib/asm/msxdos.inc

dos_scode.o:dos_scode.asm ../../include/msxlib/asm/msxdos.inc

-include depends
