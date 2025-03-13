TARGET=dskcall.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS_DOS1=dsk1_fmake.o dsk1_setdta.o dsk1_wrblk.o dsk1_fclose.o \
	dsk1_const.o dsk1_dirio.o \
	dsk1_fopen.o dsk1_rdblk.o dsk1_conout.o \
	dsk1_sfirst.o dsk1_snext.o dsk1_fdel.o dsk1_rdseq.o dsk1_fren.o \
	dsk1_rename.o dsk1_login.o dsk1_alloc.o dsk1_rdrnd.o dsk1_remove.o dsk1_wrseq.o dsk1_wrrnd.o dsk1_fsize.o dsk1_setrnd.o \
	dsk1_wrzer.o dsk1_gdate.o dsk1_sdate.o dsk1_gtime.o dsk1_stime.o dsk1_term0.o dsk1_auxin.o dsk1_auxout.o dsk1_lstout.o \
	dsk1_dirin.o dsk1_innoe.o dsk1_bufin.o dsk1_cpmver.o dsk1_dskrst.o dsk1_seldsk.o dsk1_curdrv.o dsk1_verify.o dsk1_rdabs.o \
	dsk1_wrabs.o
OBJS_DOS2=dsk2_create.o dsk2_write.o dsk2_open.o dsk2_close.o \
	dsk2_defab.o dsk2_dosver.o dsk2_defer.o dsk2_parse.o dsk2_pfile.o \
	dsk2_read.o dsk2_seek.o dsk2_ffirst.o dsk2_fnext.o
OBJS=$(OBJS_DOS1) $(OBJS_DOS2)
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

dsk2_create.o:dsk2_create.asm ../../include/msxlib/asm/msxdos.inc
dsk2_create.asm:../doscall/dos2_create.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_write.o:dsk2_write.asm ../../include/msxlib/asm/msxdos.inc
dsk2_write.asm:../doscall/dos2_write.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_close.o:dsk2_close.asm ../../include/msxlib/asm/msxdos.inc
dsk2_close.asm:../doscall/dos2_close.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fmake.o:dsk1_fmake.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fmake.asm:../doscall/dos1_fmake.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_setdta.o:dsk1_setdta.asm ../../include/msxlib/asm/msxdos.inc
dsk1_setdta.asm:../doscall/dos1_setdta.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_wrblk.o:dsk1_wrblk.asm ../../include/msxlib/asm/msxdos.inc
dsk1_wrblk.asm:../doscall/dos1_wrblk.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fclose.o:dsk1_fclose.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fclose.asm:../doscall/dos1_fclose.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_const.o:dsk1_const.asm ../../include/msxlib/asm/msxdos.inc
dsk1_const.asm:../doscall/dos1_const.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_dirio.o:dsk1_dirio.asm ../../include/msxlib/asm/msxdos.inc
dsk1_dirio.asm:../doscall/dos1_dirio.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_defab.o:dsk2_defab.asm ../../include/msxlib/asm/msxdos.inc
dsk2_defab.asm:../doscall/dos2_defab.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_dosver.o:dsk2_dosver.asm ../../include/msxlib/asm/msxdos.inc
dsk2_dosver.asm:../doscall/dos2_dosver.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_defer.o:dsk2_defer.asm ../../include/msxlib/asm/msxdos.inc
dsk2_defer.asm:../doscall/dos2_defer.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_parse.o:dsk2_parse.asm ../../include/msxlib/asm/msxdos.inc
dsk2_parse.asm:../doscall/dos2_parse.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_pfile.o:dsk2_pfile.asm ../../include/msxlib/asm/msxdos.inc
dsk2_pfile.asm:../doscall/dos2_pfile.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fopen.o:dsk1_fopen.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fopen.asm:../doscall/dos1_fopen.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_rdblk.o:dsk1_rdblk.asm ../../include/msxlib/asm/msxdos.inc
dsk1_rdblk.asm:../doscall/dos1_rdblk.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_conout.o:dsk1_conout.asm ../../include/msxlib/asm/msxdos.inc
dsk1_conout.asm:../doscall/dos1_conout.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_open.o:dsk2_open.asm ../../include/msxlib/asm/msxdos.inc
dsk2_open.asm:../doscall/dos2_open.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_read.o:dsk2_read.asm ../../include/msxlib/asm/msxdos.inc
dsk2_read.asm:../doscall/dos2_read.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_seek.o:dsk2_seek.asm ../../include/msxlib/asm/msxdos.inc
dsk2_seek.asm:../doscall/dos2_seek.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_sfirst.o:dsk1_sfirst.asm ../../include/msxlib/asm/msxdos.inc
dsk1_sfirst.asm:../doscall/dos1_sfirst.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_snext.o:dsk1_snext.asm ../../include/msxlib/asm/msxdos.inc
dsk1_snext.asm:../doscall/dos1_snext.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_ffirst.o:dsk2_ffirst.asm ../../include/msxlib/asm/msxdos.inc
dsk2_ffirst.asm:../doscall/dos2_ffirst.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk2_fnext.o:dsk2_fnext.asm ../../include/msxlib/asm/msxdos.inc
dsk2_fnext.asm:../doscall/dos2_fnext.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fdel.o:dsk1_fdel.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fdel.asm:../doscall/dos1_fdel.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_rdseq.o:dsk1_rdseq.asm ../../include/msxlib/asm/msxdos.inc
dsk1_rdseq.asm:../doscall/dos1_rdseq.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fren.o:dsk1_fren.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fren.asm:../doscall/dos1_fren.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_login.o:dsk1_login.asm ../../include/msxlib/asm/msxdos.inc
dsk1_login.asm:../doscall/dos1_login.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_alloc.o:dsk1_alloc.asm ../../include/msxlib/asm/msxdos.inc
dsk1_alloc.asm:../doscall/dos1_alloc.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_rdrnd.o:dsk1_rdrnd.asm ../../include/msxlib/asm/msxdos.inc
dsk1_rdrnd.asm:../doscall/dos1_rdrnd.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_wrseq.o:dsk1_wrseq.asm ../../include/msxlib/asm/msxdos.inc
dsk1_wrseq.asm:../doscall/dos1_wrseq.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_wrrnd.o:dsk1_wrrnd.asm ../../include/msxlib/asm/msxdos.inc
dsk1_wrrnd.asm:../doscall/dos1_wrrnd.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_fsize.o:dsk1_fsize.asm ../../include/msxlib/asm/msxdos.inc
dsk1_fsize.asm:../doscall/dos1_fsize.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_setrnd.o:dsk1_setrnd.asm ../../include/msxlib/asm/msxdos.inc
dsk1_setrnd.asm:../doscall/dos1_setrnd.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_wrzer.o:dsk1_wrzer.asm ../../include/msxlib/asm/msxdos.inc
dsk1_wrzer.asm:../doscall/dos1_wrzer.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_gdate.o:dsk1_gdate.asm ../../include/msxlib/asm/msxdos.inc
dsk1_gdate.asm:../doscall/dos1_gdate.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_sdate.o:dsk1_sdate.asm ../../include/msxlib/asm/msxdos.inc
dsk1_sdate.asm:../doscall/dos1_sdate.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_gtime.o:dsk1_gtime.asm ../../include/msxlib/asm/msxdos.inc
dsk1_gtime.asm:../doscall/dos1_gtime.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_stime.o:dsk1_stime.asm ../../include/msxlib/asm/msxdos.inc
dsk1_stime.asm:../doscall/dos1_stime.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_term0.o:dsk1_term0.asm ../../include/msxlib/asm/msxdos.inc
dsk1_term0.asm:../doscall/dos1_term0.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_auxin.o:dsk1_auxin.asm ../../include/msxlib/asm/msxdos.inc
dsk1_auxin.asm:../doscall/dos1_auxin.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_auxout.o:dsk1_auxout.asm ../../include/msxlib/asm/msxdos.inc
dsk1_auxout.asm:../doscall/dos1_auxout.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_lstout.o:dsk1_lstout.asm ../../include/msxlib/asm/msxdos.inc
dsk1_lstout.asm:../doscall/dos1_lstout.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_dirin.o:dsk1_dirin.asm ../../include/msxlib/asm/msxdos.inc
dsk1_dirin.asm:../doscall/dos1_dirin.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_innoe.o:dsk1_innoe.asm ../../include/msxlib/asm/msxdos.inc
dsk1_innoe.asm:../doscall/dos1_innoe.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_bufin.o:dsk1_bufin.asm ../../include/msxlib/asm/msxdos.inc
dsk1_bufin.asm:../doscall/dos1_bufin.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_cpmver.o:dsk1_cpmver.asm ../../include/msxlib/asm/msxdos.inc
dsk1_cpmver.asm:../doscall/dos1_cpmver.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_dskrst.o:dsk1_dskrst.asm ../../include/msxlib/asm/msxdos.inc
dsk1_dskrst.asm:../doscall/dos1_dskrst.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_seldsk.o:dsk1_seldsk.asm ../../include/msxlib/asm/msxdos.inc
dsk1_seldsk.asm:../doscall/dos1_seldsk.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_curdrv.o:dsk1_curdrv.asm ../../include/msxlib/asm/msxdos.inc
dsk1_curdrv.asm:../doscall/dos1_curdrv.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_verify.o:dsk1_verify.asm ../../include/msxlib/asm/msxdos.inc
dsk1_verify.asm:../doscall/dos1_verify.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_rdabs.o:dsk1_rdabs.asm ../../include/msxlib/asm/msxdos.inc
dsk1_rdabs.asm:../doscall/dos1_rdabs.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

dsk1_wrabs.o:dsk1_wrabs.asm ../../include/msxlib/asm/msxdos.inc
dsk1_wrabs.asm:../doscall/dos1_wrabs.asm ../../include/msxlib/asm/msxdos.inc
	../mk_dskcallversion.sh $< $@

### Clang
dsk1_rename.o:dsk1_rename.c
dsk1_rename.c:../doscall/dos1_rename.c
	../mk_dskcallversion_c.sh $< $@

dsk1_remove.o:dsk1_remove.c
dsk1_remove.c:../doscall/dos1_remove.c
	../mk_dskcallversion_c.sh $< $@


-include depends
