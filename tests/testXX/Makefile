DOS1_DIR=dos1
DOS2_DIR=dos2
DISK1_DIR=disk1
DISK2_DIR=disk2
TARGET1_DOS1=$(DOS1_DIR)/testXXa.com
TARGET1_DOS2=$(DOS2_DIR)/testXXb.com
TARGET2_DOS2=$(DOS2_DIR)/testAS.com
TARGET3_DOS2=$(DOS2_DIR)/hello.com
TARGET4_DOS2=$(DOS2_DIR)/test4b.com
TARGET5_DISK1=$(DISK1_DIR)/test5a.msx
TARGET5_DISK2=$(DISK2_DIR)/test5b.msx
TARGET5_DOS1=$(DOS1_DIR)/test5a.com
TARGET5_DOS2=$(DOS2_DIR)/test5b.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS1_DOS1=$(DOS1_DIR)/testXX.o
OBJS1_DOS2=$(DOS2_DIR)/testXX.o
OBJS2_DOS2=$(DOS2_DIR)/testAS.o
OBJS3_DOS2=$(DOS2_DIR)/hello.o
OBJS4_DOS2=$(DOS2_DIR)/test4.o $(DOS2_DIR)/test4_c.o
OBJS5_DISK1=$(DISK1_DIR)/test5.o
OBJS5_DISK2=$(DISK2_DIR)/test5.o
OBJS5_DOS1=$(DOS1_DIR)/test5.o
OBJS5_DOS2=$(DOS2_DIR)/test5.o
CFLAGS_INC_DOS1=-I../../include -I../common -D__MSXDOS__=1 -DAMALLOC
CFLAGS_INC_DOS2=-I../../include -I../common -D__MSXDOS__=2 -DAMALLOC
CFLAGS_INC_DISK1=-I../../include -I../common
CFLAGS_INC_DISK2=-I../../include -I../common
CFLAGS_DOS1=+msx -subtype=msxdos -O2
CFLAGS_DOS2=+msx -subtype=msxdos2 -O2
CFLAGS_DISK1=+msx -subtype=diskio --msxdos1 -O2
CFLAGS_DISK2=+msx -subtype=diskio --msxdos2 -O2
ASCONFIGS_DOS1=$(CFLAGS_INC_DOS1)
ASCONFIGS_DOS2=$(CFLAGS_INC_DOS2)
ASCONFIGS_DISK1=$(CFLAGS_INC_DISK1)
ASCONFIGS_DISK2=$(CFLAGS_INC_DISK2)
LDCONFIG=-L../../libs

all:$(TARGET1_DOS1) $(TARGET1_DOS2) $(TARGET2_DOS2) $(TARGET3_DOS2) $(TARGET4_DOS2) $(TARGET5_DISK1) $(TARGET5_DISK2) $(TARGET5_DOS1) $(TARGET5_DOS2)

$(TARGET1_DOS1):$(DOS1_DIR) $(OBJS1_DOS1) ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS1) -pragma-include:zpragma1.inc -create-app -m -o $(TARGET1_DOS1) $(OBJS1_DOS1) $(LDCONFIG) -ldoscall -lm

$(TARGET1_DOS2):$(DOS2_DIR) $(OBJS1_DOS2) ../../libs/doscall.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS2) -pragma-include:testXXb.inc -create-app -m -o $(TARGET1_DOS2) $(OBJS1_DOS2) $(LDCONFIG) -ldoscall -lmsxlib -lm

$(TARGET2_DOS2):$(DOS2_DIR) $(OBJS2_DOS2)
	$(CC) $(CFLAGS_DOS2) -pragma-include:testXXb.inc --no-crt -create-app -m -o $(TARGET2_DOS2) $(OBJS2_DOS2)

$(TARGET3_DOS2):$(DOS2_DIR) $(OBJS3_DOS2) ../../libs/bios.lib Makefile ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS2) -pragma-include:../../pragma/msxdos2.def -pragma-define:CLIB_FIRMWARE_KEYBOARD_CLICK=0 -create-app -v -m -s --list -o $(TARGET3_DOS2) $(OBJS3_DOS2) $(LDCONFIG) -lm -lbios -lmsxlib

$(TARGET4_DOS2):$(DOS2_DIR) $(OBJS4_DOS2) Makefile
	$(CC) $(CFLAGS_DOS2) -create-app -v -m -o $(TARGET4_DOS2) $(OBJS4_DOS2)

$(TARGET5_DISK1):$(DISK1_DIR) $(OBJS5_DISK1) Makefile ../../libs/doscall.lib
	$(CC) $(CFLAGS_DISK1) -create-app -v -m -o $(TARGET5_DISK1) $(OBJS5_DISK1) $(LDCONFIG) -ldoscall

$(TARGET5_DISK2):$(DISK2_DIR) $(OBJS5_DISK2) Makefile ../../libs/doscall.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DISK2) -create-app -pragma-include:../../pragma/disk2.def -m -o $(TARGET5_DISK2) $(OBJS5_DISK2) $(LDCONFIG) -lmsxlib -ldoscall

$(TARGET5_DOS1):$(DOS1_DIR) $(OBJS5_DOS1) ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS1) -create-app -m -o $(TARGET5_DOS1) $(OBJS5_DOS1) $(LDCONFIG) $(LDCONFIG) -ldoscall -lm

$(TARGET5_DOS2):$(DOS2_DIR) $(OBJS5_DOS2) ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS2) -create-app -m -o $(TARGET5_DOS2) $(OBJS5_DOS2) $(LDCONFIG) -lm -ldoscall

$(DOS1_DIR):
	mkdir -p $(DOS1_DIR)

$(DOS2_DIR):
	mkdir -p $(DOS2_DIR)

$(DISK1_DIR):
	mkdir -p $(DISK1_DIR)

$(DISK2_DIR):
	mkdir -p $(DISK2_DIR)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS_DOS1) $<

$(DOS1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -vn -o $@ -c $<

$(DOS2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -vn -o $@ -c $<

$(DISK1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DISK1) $(CFLAGS_INC_DISK1) -vn -o $@ -c $<

$(DISK2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DISK2) $(CFLAGS_INC_DISK2) -vn -o $@ -c $<

$(DOS1_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS1) -o=$@ $<

$(DOS2_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS2) -o=$@ $<

$(DISK1_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DISK1) -o=$@ $<

$(DISK2_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DISK2) -o=$@ $<

clean:
	rm -rf *.c.asm *.map *.img *.msx *.lis *.sym $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:$(TARGET)
#	emmy80 $(TARGET)

-include depends
