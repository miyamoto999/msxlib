TARGET=msxlib.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
BFILE_OBJS=bfile/bfile_open_dos1.o \
	bfile/bfile_malloc_dos1.o \
	bfile/bfile_read_dos1.o \
	bfile/bfile_write_dos1.o \
	bfile/bfile_close_dos1.o \
	bfile/bfile_create_dos1.o \
	bfile/bfile_write_dos2.o \
	bfile/bfile_create_dos2.o \
	bfile/bfile_close_dos2.o \
	bfile/bfile_open_dos2.o \
	bfile/bfile_read_dos2.o \
	bfile/bfile_fseek_dos1.o \
	bfile/bfile_fseek_dos2.o \
	bfile/bfile_flush_dos1.o \
	bfile/bfile_flush_dos2.o
RBUF_OBJS=rbuf/rbuf.o rbuf/rbuf_add_data.o rbuf/rbuf_get_data.o rbuf/rbuf_get_size.o \
	rbuf/rbuf_read.o rbuf/cif_rbuf_add_data.o rbuf/cif_rbuf_get_data.o rbuf/cif_rbuf_get_size.o rbuf/cif_rbuf_read.o
NET_OBJS=net/net_init.o net/net_setup.o net/net_connect.o net/net_readline.o
BCDF_OBJS=bcdf/bcdf2dbl.o  bcdf/bcdf2str.o  bcdf/str2bcdf.o
FCNTL_OBJS=fcntl/msxdos2/open_dos2.o
STDIO_OBJS=stdio/fgetc_cons_dos.o stdio/fputc_cons_dos.o
OBJS=$(BFILE_OBJS) $(RBUF_OBJS) $(NET_OBJS) $(BCDF_OBJS) $(STDIO_OBJS) $(FCNTL_OBJS) msx_dos_inpkey.o msx_dct_inpkey.o  msx_fcb_init.o strlen.o \
	pre_printf.o pre_printf_sdcc.o msx_fcb_init_ren.o msx_fcb_init_filename.o msx_knj.o msx_get_reg_sp.o
	
CFLAGS_INC=-I../include
CFLAGS=+msx $(CFLAGS_INC) -O
ASCONFIGS=$(CFLAGS_INC) -I$(ZCCCFG)/../../lib
DIRS=iot bios vdp slot doscall asmroutine

all:$(TARGET)
	@for i in $(DIRS); \
	do \
		make -C $$i all; \
		ret=$$?;	\
		if [ $$ret -ne 0 ]; then \
			exit $$ret; \
			break; \
		fi \
	done

$(TARGET):$(OBJS)
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
	rm -f $(OBJS) $(TARGET) *.c.asm
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
	gcc $(CFLAGS_INC) -E -MM -w bfile/*.c | python add_prefix.py bfile/ >> depends
	gcc $(CFLAGS_INC) -E -MM -w rbuf/*.c | python add_prefix.py rbuf/ >> depends
	gcc $(CFLAGS_INC) -E -MM -w net/*.c | python add_prefix.py net/ >> depends
	gcc $(CFLAGS_INC) -E -MM -w bcdf/*.c | python add_prefix.py net/ >> depends
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

msx_dos_inpkey.o: msx_dos_inpkey.asm ../include/msxlib/asm/msxbios.inc ../include/msxlib/asm/msxwork.inc
msx_dct_inpkey.o: msx_dct_inpkey.asm ../include/msxlib/asm/msxbios.inc
rbuf/rbuf_add_data.o: rbuf/rbuf_add_data.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_get_data.o: rbuf/rbuf_get_data.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_get_size.o: rbuf/rbuf_get_size.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_read.o: rbuf/rbuf_read.asm ../include/msxlib/asm/rbuf.inc

pre_printf_sdcc.o: pre_printf_sdcc.c
	$(CC) -compiler=sdcc $(CFLAGS) -vn -c $<

strlen.o:strlen.asm

msx_knj.o: msx_knj.asm ../include/msxlib/asm/msxwork.inc

fcntl/msxdos2/open_dos2.o:fcntl/msxdos2/open_dos2.asm
fcntl/msxdos2/open_dos2.asm:$(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/open.asm
	mkdir -p fcntl/msxdos2
	cat $(ZCCCFG)/../../libsrc/target/msx/fcntl/msxdos2/open.asm | sed -e 's/open/open_dos2/g' -e 's/MSXDOS/msxlib_doscall/g' > fcntl/msxdos2/open_dos2.asm

tests:

-include depends
