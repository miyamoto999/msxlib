DOS1_DIR=dos1
DOS2_DIR=dos2
CPM_DIR=cpm
DSK1_DIR=dsk1
DSK2_DIR=dsk2
TARGET_DOS1=$(DOS1_DIR)/test017.com
TARGET_DOS2=$(DOS2_DIR)/test017.com
TARGET_CPM=$(CPM_DIR)/test017.com
TARGET_DSK1=$(DSK1_DIR)/test017.bin
TARGET_DSK2=$(DSK2_DIR)/test017.bin
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS_DOS1=$(DOS1_DIR)/test017.o
OBJS_DOS2=$(patsubst $(DOS1_DIR)/%, $(DOS2_DIR)/%, $(OBJS_DOS1))
OBJS_CPM=$(patsubst $(DOS1_DIR)/%, $(CPM_DIR)/%, $(OBJS_DOS1))
OBJS_DSK1=$(patsubst $(DOS1_DIR)/%, $(DSK1_DIR)/%, $(OBJS_DOS1))
OBJS_DSK2=$(patsubst $(DOS1_DIR)/%, $(DSK2_DIR)/%, $(OBJS_DOS1))
CFLAGS_INC_DOS1=-I../../include -D__MSXDOS__=1
CFLAGS_DOS1=+msx -subtype=msxdos
CFLAGS_INC_DOS2=-I../../include -D__MSXDOS__=2
CFLAGS_DOS2=+msx -subtype=msxdos2
CFLAGS_INC_CPM=-I../../include -D__MSXDOS__=1
CFLAGS_CPM=+cpm
CFLAGS_INC_DSK1=-I../../include -D__DSKBAS__=1
CFLAGS_DSK1=+msx -subtype=bin
CFLAGS_INC_DSK2=-I../../include -D__DSKBAS__=2
CFLAGS_DSK2=+msx -subtype=bin
ASCONFIGS_DOS1=$(CFLAGS_INC_DOS1)
ASCONFIGS_DOS2=$(CFLAGS_INC_DOS2)
ASCONFIGS_CPM=$(CFLAGS_INC_CPM)
ASCONFIGS_DSK1=$(CFLAGS_INC_DSK1)
ASCONFIGS_DSK2=$(CFLAGS_INC_DSK2)

all:$(TARGET_DOS1) $(TARGET_CPM)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) -L../../libs -lmsxlib -ldoscall

$(TARGET_DOS2):$(DOS2_DIR) $(OBJS_DOS2) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS2) -create-app -m -o $(TARGET_DOS2) $(OBJS_DOS2) -L../../libs -lmsxlib -ldoscall

$(TARGET_CPM):$(CPM_DIR) $(OBJS_CPM) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_CPM) -create-app -m -o $(TARGET_CPM) $(OBJS_CPM) -L../../libs -lmsxlib -ldoscall

$(TARGET_DSK1):$(DSK1_DIR) $(OBJS_DSK1) ../../libs/msxlib.lib ../../libs/dskcall.lib
	$(CC) $(CFLAGS_DSK1) -create-app -m -o $(TARGET_DSK1) $(OBJS_DSK1) -L../../libs -lmsxlib -ldskcall

$(TARGET_DSK2):$(DSK2_DIR) $(OBJS_DSK2) ../../libs/msxlib.lib ../../libs/dskcall.lib
	$(CC) $(CFLAGS_DSK2) -create-app -m -o $(TARGET_DSK2) $(OBJS_DSK2) -L../../libs -lmsxlib -ldskcall

$(DOS1_DIR):
	mkdir -p $(DOS1_DIR)

$(DOS2_DIR):
	mkdir -p $(DOS2_DIR)

$(CPM_DIR):
	mkdir -p $(CPM_DIR)

$(DSK1_DIR):
	mkdir -p $(DSK1_DIR)

$(DSK2_DIR):
	mkdir -p $(DSK2_DIR)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS_DOS1) $<

$(DOS1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -O --no-crt -o $@ -c $<
#	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -O --no-crt -o $(@:.o=.c.asm) -S $<

$(DOS2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -O --no-crt -o $@ -c $<
#	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -O --no-crt -o $(@:.o=.c.asm) -S $<

$(CPM_DIR)/%.o:%.c
	$(CC) $(CFLAGS_CPM) $(CFLAGS_INC_CPM) -O --no-crt -o $@ -c $<
#	$(CC) $(CFLAGS_CPM) $(CFLAGS_INC_CPM) -O --no-crt -o $(@:.o=.c.asm) -S $<

$(DSK1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DSK1) $(CFLAGS_INC_DSK1) -O --no-crt -o $@ -c $<
#	$(CC) $(CFLAGS_DSK1) $(CFLAGS_INC_DSK1) -O --no-crt -o $(@:.o=.c.asm) -S $<

$(DSK2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DSK2) $(CFLAGS_INC_DSK2) -O --no-crt -o $@ -c $<
#	$(CC) $(CFLAGS_DSK1) $(CFLAGS_INC_DSK1) -O --no-crt -o $(@:.o=.c.asm) -S $<

clean:
	rm -rf *.c.asm *.map *.img *.msx $(DOS1_DIR) $(DOS2_DIR) $(CPM_DIR) $(DSK1_DIR) $(DSK2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:

-include depends
