TARGET=dskcall.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=dsk2_create.o dsk2_write.o dsk2_close.o dsk1_fmake.o dsk1_setdta.o dsk1_wrblk.o dsk1_fclose.o dsk1_const.o dsk1_dirio.o \
	dsk2_defab.o dsk2_dosver.o dsk2_defer.o dsk2_parse.o dsk2_pfile.o dsk1_fopen.o dsk1_rdblk.o dsk1_conout.o dsk2_open.o \
	dsk2_read.o dsk2_seek.o
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

-include depends
