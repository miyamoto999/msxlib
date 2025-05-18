TARGET=msxlib.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
BFILE_C_SRCS=bfile/bfile_close_dos1.c bfile/bfile_close_dos2.c bfile/bfile_create_dos1.c \
		bfile/bfile_create_dos2.c bfile/bfile_flush_dos1.c bfile/bfile_flush_dos2.c \
		bfile/bfile_fseek_dos1.c bfile/bfile_fseek_dos2.c bfile/bfile_malloc_dos1.c \
		bfile/bfile_open_dos1.c bfile/bfile_open_dos2.c bfile/bfile_read_dos1.c \
		bfile/bfile_read_dos2.c bfile/bfile_write_dos1.c bfile/bfile_write_dos2.c
BFILE_ASM_SRCS=
BFILE_OBJS=$(patsubst %.c, %.o, $(BFILE_C_SRCS)) $(patsubst %.asm, %.o, $(BFILE_ASM_SRCS))

RBUF_C_SRCS=rbuf/rbuf.c
RBUF_ASM_SRCS=rbuf/cif_rbuf_add_data.asm rbuf/cif_rbuf_get_data.asm rbuf/cif_rbuf_get_size.asm \
		rbuf/cif_rbuf_read.asm rbuf/rbuf_add_data.asm rbuf/rbuf_get_data.asm \
		rbuf/rbuf_get_size.asm rbuf/rbuf_read.asm
RBUF_OBJS=$(patsubst %.c, %.o, $(RBUF_C_SRCS)) $(patsubst %.asm, %.o, $(RBUF_ASM_SRCS))

BCDF_C_SRCS=bcdf/bcdf2dbl.c bcdf/bcdf2str.c bcdf/str2bcdf.c
BCDF_ASM_SRCS=
BCDF_OBJS=$(patsubst %.c, %.o, $(BCDF_C_SRCS)) $(patsubst %.asm, %.o, $(BCDF_ASM_SRCS))

FCNTL_DOS1_C_SRCS=fcntl/msxdos1/close_dos1.c fcntl/msxdos1/creat_dos1.c \
		fcntl/msxdos1/fdgetpos_dos1.c fcntl/msxdos1/fdtell_dos1.c fcntl/msxdos1/fsync_dos1.c \
		fcntl/msxdos1/lseek_dos1.c fcntl/msxdos1/open_dos1.c fcntl/msxdos1/read_dos1.c \
		fcntl/msxdos1/stat_dos1.c fcntl/msxdos1/write_dos1.c
FCNTL_DOS1_ASM_SRCS=
FCNTL_DOS1_OBJS=$(patsubst %.c, %.o, $(FCNTL_DOS1_C_SRCS)) $(patsubst %.asm, %.o, $(FCNTL_DOS1_ASM_SRCS))

FCNTL_DOS2_C_SRCS=
FCNTL_DOS2_ASM_SRCS=fcntl/msxdos2/creat_dos2.asm fcntl/msxdos2/open_dos2.asm
FCNTL_DOS2_OBJS=$(patsubst %.c, %.o, $(FCNTL_DOS2_C_SRCS)) $(patsubst %.asm, %.o, $(FCNTL_DOS2_ASM_SRCS))

STDIO_C_SRCS=
STDIO_ASM_SRCS=stdio/fgetc_cons_dos.asm stdio/fputc_cons_dos.asm
STDIO_OBJS=$(patsubst %.c, %.o, $(STDIO_C_SRCS)) $(patsubst %.asm, %.o, $(STDIO_ASM_SRCS))

DOSCALL_C_SRCS=doscall/dos1_remove.c doscall/dos1_rename.c
DOSCALL_ASM_SRCS=doscall/dos_getkerver.asm doscall/dos_scode.asm doscall/dos1_alloc.asm \
		doscall/dos1_auxin.asm doscall/dos1_auxout.asm doscall/dos1_bufin.asm \
		doscall/dos1_conout.asm doscall/dos1_const.asm doscall/dos1_cpmver.asm \
		doscall/dos1_curdrv.asm doscall/dos1_dirin.asm doscall/dos1_dirio.asm \
		doscall/dos1_dskrst.asm doscall/dos1_fclose.asm doscall/dos1_fdel.asm \
		doscall/dos1_fmake.asm doscall/dos1_fopen.asm doscall/dos1_fren.asm \
		doscall/dos1_fsize.asm doscall/dos1_gdate.asm doscall/dos1_gtime.asm \
		doscall/dos1_innoe.asm doscall/dos1_login.asm doscall/dos1_lstout.asm \
		doscall/dos1_rdabs.asm doscall/dos1_rdblk.asm doscall/dos1_rdrnd.asm \
		doscall/dos1_rdseq.asm doscall/dos1_sdate.asm doscall/dos1_seldsk.asm \
		doscall/dos1_setdta.asm doscall/dos1_setrnd.asm doscall/dos1_sfirst.asm \
		doscall/dos1_snext.asm doscall/dos1_stime.asm doscall/dos1_term0.asm \
		doscall/dos1_verify.asm doscall/dos1_wrabs.asm doscall/dos1_wrblk.asm \
		doscall/dos1_wrrnd.asm doscall/dos1_wrseq.asm doscall/dos1_wrzer.asm \
		doscall/dos2_close.asm doscall/dos2_create.asm doscall/dos2_defab.asm \
		doscall/dos2_defer.asm doscall/dos2_dosver.asm doscall/dos2_ffirst.asm \
		doscall/dos2_fnext.asm doscall/dos2_ftime.asm doscall/dos2_ioctl.asm \
		doscall/dos2_open.asm doscall/dos2_parse.asm doscall/dos2_pfile.asm \
		doscall/dos2_read.asm doscall/dos2_seek.asm doscall/dos2_write.asm \
		doscall/msxlib_doscall.asm
DOSCALL_OBJS=$(patsubst %.c, %.o, $(DOSCALL_C_SRCS)) $(patsubst %.asm, %.o, $(DOSCALL_ASM_SRCS))

BIOS_C_SRCS=
BIOS_ASM_SRCS=bios/dos_extrom.asm bios/msxmain_dct_chgclr.asm bios/msxmain_dct_chget.asm \
		bios/msxmain_dct_chgmod.asm bios/msxmain_dct_chput.asm bios/msxmain_dct_grpprt.asm \
		bios/msxmain_dct_gtpad.asm bios/msxmain_dct_kilbuf.asm bios/msxmain_dct_snsmat.asm \
		bios/msxmain_dos_chgclr.asm bios/msxmain_dos_chget.asm bios/msxmain_dos_chgmod.asm \
		bios/msxmain_dos_chput.asm bios/msxmain_dos_grpprt.asm bios/msxmain_dos_gtpad.asm \
		bios/msxmain_dos_kilbuf.asm bios/msxmain_dos_snsmat.asm bios/msxsub_dct_chgmdp.asm \
		bios/msxsub_dct_cls.asm bios/msxsub_dct_iniplt.asm bios/msxsub_dct_knjprt.asm \
		bios/msxsub_dct_redclk.asm bios/msxsub_dct_setplt.asm bios/msxsub_dos_chgmdp.asm \
		bios/msxsub_dos_cls.asm bios/msxsub_dos_iniplt.asm bios/msxsub_dos_knjprt.asm \
		bios/msxsub_dos_redclk.asm bios/msxsub_dos_setplt.asm
BIOS_OBJS=$(patsubst %.c, %.o, $(BIOS_C_SRCS)) $(patsubst %.asm, %.o, $(BIOS_ASM_SRCS))

ASMROUTINE_C_SRCS=
ASMROUTINE_ASM_SRCS=asmroutine/disphex.asm asmroutine/dump.asm asmroutine/dump2.asm \
		asmroutine/out_crlf.asm asmroutine/out_spc.asm
ASMROUTINE_OBJS=$(patsubst %.c, %.o, $(ASMROUTINE_C_SRCS)) $(patsubst %.asm, %.o, $(ASMROUTINE_ASM_SRCS))

SLOT_C_SRCS=
SLOT_ASM_SRCS=slot/msxslot_rdslt.asm
SLOT_OBJS=$(patsubst %.c, %.o, $(SLOT_C_SRCS)) $(patsubst %.asm, %.o, $(SLOT_ASM_SRCS))

MSXLIB_C_SRCS=dostime2time.c dostime2tm.c msx_fcb_init_filename.c msx_fcb_init_ren.c \
		msx_fcb_init.c pre_printf_sdcc.c pre_printf.c
MSXLIB_ASM_SRCS=msx_dct_inpkey.asm msx_dos_inpkey.asm msx_get_reg_sp.asm msx_knj.asm \
		strlen.asm
MSXLIB_OBJS=$(patsubst %.c, %.o, $(MSXLIB_C_SRCS)) $(patsubst %.asm, %.o, $(MSXLIB_ASM_SRCS))

CRT0_FILES=../crt0/msx_crt0.asm ../crt0/msxdos.asm ../crt0/crt_dos1_fcntl.inc ../crt0/ram.asm

OBJS=$(BFILE_OBJS) $(RBUF_OBJS) $(BCDF_OBJS) $(STDIO_OBJS) $(FCNTL_DOS1_OBJS) $(FCNTL_DOS2_OBJS) $(DOSCALL_OBJS) $(MSXLIB_OBJS) $(BIOS_OBJS) $(ASMROUTINE_OBJS) $(SLOT_OBJS)
	
CFLAGS_INC=-I../include
CFLAGS=+msx $(CFLAGS_INC) -O
ASCONFIGS=$(CFLAGS_INC) -I$(ZCCCFG)/../../lib
DIRS=iot vdp

all: $(CRT0_FILES) $(TARGET)
	@for i in $(DIRS); \
	do \
		make -C $$i all; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

$(TARGET): $(OBJS)
	$(LD) -x$(TARGET) $(OBJS)
	cp -p $(TARGET) ../libs

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -vn -c $<
#	$(CC) $(CFLAGS) --no-crt -S $<

clean:
	rm -f $(OBJS) $(TARGET) *.c.asm ../libs/*.lib
	@for i in $(DIRS); \
	do \
		make -C $$i clean; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) *.asm >> depends
	gcc $(CFLAGS_INC) -E -MM -w bfile/*.c | python ../tools/add_prefix.py bfile/ >> depends
	gcc $(CFLAGS_INC) -E -MM -w rbuf/*.c | python ../tools/add_prefix.py rbuf/ >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) rbuf/*.asm >> depends
	gcc $(CFLAGS_INC) -E -MM -w bcdf/*.c | python ../tools/add_prefix.py bcdf/ >> depends
	gcc $(CFLAGS_INC) -E -MM -w fcntl/msxdos1/*.c | python ../tools/add_prefix.py fcntl/msxdos1/ >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) fcntl/msxdos2/*.asm >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) bios/*.asm >> depends
	gcc $(CFLAGS_INC) -E -MM -w doscall/*.c | python ../tools/add_prefix.py doscall/ >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) doscall/*.asm >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) asmroutine/*.asm >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) slot/*.asm >> depends
	python ../tools/mkdepasm.py $(CFLAGS_INC) stdio/*.asm >> depends
	@for i in $(DIRS); \
	do \
		make -C $$i depend; \
	done

z80_int.o: z80_int.asm

../include/msxlib/msxbiosaddr.h:../include/msxlib/asm/msxbios.inc
	python ../tools/convdef.py $< $@

../include/msxlib/msxworkaddr.h:../include/msxlib/asm/msxwork.inc
	python ../tools/convdef.py $< $@

../include/msxlib/iotaddr.h:../include/msxlib/asm/iot.inc
	python ../tools/convdef.py $< $@

pre_printf_sdcc.o: pre_printf_sdcc.c
	$(CC) -compiler=sdcc $(CFLAGS) -vn -c $<

fcntl/msxdos2/open_dos2.asm:$(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/open.asm
	mkdir -p fcntl/msxdos2
	cat $(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/open.asm | sed -e 's/open/open_dos2/g' -e 's/MSXDOS/msxlib_doscall/g' > fcntl/msxdos2/open_dos2.asm

fcntl/msxdos2/creat_dos2.asm:$(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/creat.asm
	mkdir -p fcntl/msxdos2
	cat $(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/creat.asm | sed -e 's/creat/creat_dos2/g' -e 's/MSXDOS/msxlib_doscall/g' -e 's/ld      a, 1                        ;O_WRONLY/ld      a, 2                        ;O_WRONLY/g' > fcntl/msxdos2/creat_dos2.asm

../crt0/msx_crt0.asm: $(ZCCCFG)/../../lib/target/msx/classic/msx_crt0.asm
	cat $(ZCCCFG)/../../lib/target/msx/classic/msx_crt0.asm | sed -e 's/target\/msx\/classic\/msxdos.asm/msxdos.asm/g' -e 's/target\/msx\/classic\/ram.asm/ram.asm/g' > ../crt0/msx_crt0.asm

../crt0/msxdos.asm: $(ZCCCFG)/../../lib/target/msx/classic/msxdos.asm
	cat $(ZCCCFG)/../../lib/target/msx/classic/msxdos.asm | sed -e 's/crt\/classic\/crt_cpm_fcntl.inc/crt_dos1_fcntl.inc/g' > ../crt0/msxdos.asm

../crt0/ram.asm: $(ZCCCFG)/../../lib/target/msx/classic/ram.asm
	cat $(ZCCCFG)/../../lib/target/msx/classic/ram.asm | sed -e 's/crt\/classic\/crt_cpm_fcntl.inc/crt_dos1_fcntl.inc/g' > ../crt0/ram.asm

../crt0/crt_dos1_fcntl.inc: $(ZCCCFG)/../../lib/crt/classic/crt_cpm_fcntl.inc
	cat $(ZCCCFG)/../../lib/crt/classic/crt_cpm_fcntl.inc | sed -e 's/__fcb/__msx_fcbs/g' -e 's/166/40/g' > ../crt0/crt_dos1_fcntl.inc

tests:

-include depends
