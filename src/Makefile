TARGET=msxlib.lib
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
BFILE_OBJS=bfile/bfile_open_dos1.o bfile/bfile_open_dsk1.o \
	bfile/bfile_malloc_dos1.o bfile/bfile_malloc_dsk1.o \
	bfile/bfile_read_dos1.o bfile/bfile_read_dsk1.o \
	bfile/bfile_write_dos1.o bfile/bfile_write_dsk1.o \
	bfile/bfile_close_dos1.o bfile/bfile_close_dsk1.o \
	bfile/bfile_create_dos1.o bfile/bfile_create_dsk1.o \
	bfile/bfile_write_dos2.o bfile/bfile_write_dsk2.o \
	bfile/bfile_create_dos2.o bfile/bfile_create_dsk2.o \
	bfile/bfile_close_dos2.o bfile/bfile_close_dsk2.o \
	bfile/bfile_open_dos2.o bfile/bfile_open_dsk2.o \
	bfile/bfile_read_dos2.o bfile/bfile_read_dsk2.o \
	bfile/bfile_fseek_dos1.o bfile/bfile_fseek_dsk1.o \
	bfile/bfile_fseek_dos2.o bfile/bfile_fseek_dsk2.o \
	bfile/bfile_flush_dos1.o bfile/bfile_flush_dsk1.o \
	bfile/bfile_flush_dos2.o bfile/bfile_flush_dsk2.o
RBUF_OBJS=rbuf/rbuf.o rbuf/rbuf_add_data.o rbuf/rbuf_get_data.o rbuf/rbuf_get_size.o \
	rbuf/rbuf_read.o rbuf/cif_rbuf_add_data.o rbuf/cif_rbuf_get_data.o rbuf/cif_rbuf_get_size.o rbuf/cif_rbuf_read.o
NET_OBJS=net/net_init.o net/net_setup.o net/net_connect.o net/net_readline.o 
OBJS=$(BFILE_OBJS) $(RBUF_OBJS) $(NET_OBJS) msx_dos_inpkey.o msx_dct_inpkey.o  msx_fcb_init.o strlen.o \
	pre_printf.o pre_printf_sdcc.o
	
CFLAGS_INC=-I../include
CFLAGS=+msx $(CFLAGS_INC) -O
ASCONFIGS=$(CFLAGS_INC)
DIRS=iot bios vdp slot doscall dskcall

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
	$(CC) $(CFLAGS) --no-crt -c $<
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
	@for i in $(DIRS); \
	do \
		make -C $$i depend; \
	done

z80_int.o: z80_int.asm

msx_dos_inpkey.o: msx_dos_inpkey.asm ../include/msxlib/asm/msxbios.inc ../include/msxlib/asm/msxwork.inc
msx_dct_inpkey.o: msx_dct_inpkey.asm ../include/msxlib/asm/msxbios.inc
rbuf/rbuf_add_data.o: rbuf/rbuf_add_data.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_get_data.o: rbuf/rbuf_get_data.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_get_size.o: rbuf/rbuf_get_size.asm ../include/msxlib/asm/rbuf.inc
rbuf/rbuf_read.o: rbuf/rbuf_read.asm ../include/msxlib/asm/rbuf.inc

pre_printf_sdcc.o: pre_printf_sdcc.c
	$(CC) -compiler=sdcc $(CFLAGS) -O --no-crt -c $<

strlen.o:strlen.asm

bfile/bfile_create_dsk1.c: bfile/bfile_create_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_open_dsk1.c: bfile/bfile_open_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_malloc_dsk1.c: bfile/bfile_malloc_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_read_dsk1.c: bfile/bfile_read_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_write_dsk1.c: bfile/bfile_write_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_close_dsk1.c: bfile/bfile_close_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_fseek_dsk1.c: bfile/bfile_fseek_dos1.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_flush_dsk1.c: bfile/bfile_flush_dos1.c
	./mk_dskcallversion_c.sh $< $@

bfile/bfile_write_dsk2.c: bfile/bfile_write_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_create_dsk2.c: bfile/bfile_create_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_close_dsk2.c: bfile/bfile_close_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_open_dsk2.c: bfile/bfile_open_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_read_dsk2.c: bfile/bfile_read_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_fseek_dsk2.c: bfile/bfile_fseek_dos2.c
	./mk_dskcallversion_c.sh $< $@
bfile/bfile_flush_dsk2.c: bfile/bfile_flush_dos2.c
	./mk_dskcallversion_c.sh $< $@

-include depends
