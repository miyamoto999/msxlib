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
FCNTL_DOS1_C_SRCS=$(wildcard fcntl/msxdos1/*.c)
FCNTL_DOS1_ASM_SRCS=$(wildcard fcntl/msxdos1/*.asm)
FCNTL_DOS1_OBJS=$(patsubst fcntl/msxdos1/%.c, fcntl/msxdos1/%.o, $(FCNTL_DOS1_C_SRCS)) $(patsubst fcntl/msxdos1/%.asm, fcntl/msxdos1/%.o, $(FCNTL_DOS1_ASM_SRCS))
FCNTL_DOS2_OBJS=fcntl/msxdos2/open_dos2.o fcntl/msxdos2/creat_dos2.o
STDIO_OBJS=stdio/fgetc_cons_dos.o stdio/fputc_cons_dos.o
DOSCALL_C_SRCS=$(wildcard doscall/*.c)
DOSCALL_ASM_SRCS=$(wildcard doscall/*.asm)
DOSCALL_OBJS=$(patsubst doscall/%.c, doscall/%.o, $(DOSCALL_C_SRCS)) $(patsubst doscall/%.asm, doscall/%.o, $(DOSCALL_ASM_SRCS))
MSXLIB_C_SRCS=$(wildcard *.c)
MSXLIB_ASM_SRCS=$(wildcard *.asm)
MSXLIB_OBJS=$(patsubst %.c, %.o, $(MSXLIB_C_SRCS)) $(patsubst %.asm, %.o, $(MSXLIB_ASM_SRCS))
CRT0_OBJS=../crt0/msx_crt0.asm ../crt0/msxdos.asm ../crt0/crt_dos1_fcntl.inc ../crt0/ram.asm

OBJS=$(BFILE_OBJS) $(RBUF_OBJS) $(NET_OBJS) $(BCDF_OBJS) $(STDIO_OBJS) $(FCNTL_DOS1_OBJS) $(FCNTL_DOS2_OBJS) $(DOSCALL_OBJS) $(MSXLIB_OBJS)
	
CFLAGS_INC=-I../include
CFLAGS=+msx $(CFLAGS_INC) -O
ASCONFIGS=$(CFLAGS_INC) -I$(ZCCCFG)/../../lib
DIRS=iot bios vdp slot asmroutine

all: $(CRT0_OBJS) $(TARGET)
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
	gcc $(CFLAGS_INC) -E -MM -w fcntl/msxdos1/*.c | python add_prefix.py net/ >> depends
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

fcntl/msxdos2/creat_dos2.o:fcntl/msxdos2/creat_dos2.asm
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
