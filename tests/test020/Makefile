CPM_DIR=cpm
TARGET=test020.com
TARGET_CPM=$(CPM_DIR)/test020.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS=test020.o
OBJS_CPM=$(CPM_DIR)/test020.o
CFLAGS_INC=-I../../include -I../common -D__MSXDOS__=1
CFLAGS=+msx -subtype=msxdos
CFLAGS_INC_CPM=-I../../include -I../common -D__MSXDOS__=1
CFLAGS_CPM=+cpm
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS=$(CFLAGS_INC)

all:$(TARGET) $(TARGET_CPM)

$(TARGET):$(OBJS) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS) -create-app -m -o $(TARGET) $(OBJS) -L../../libs -lmsxlib -ldoscall

$(TARGET_CPM):$(CPM_DIR) $(OBJS_CPM) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_CPM) -create-app -m -o $(TARGET_CPM) $(OBJS_CPM) -L../../libs -lmsxlib -ldoscall

$(CPM_DIR):
	mkdir -p $(CPM_DIR)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

%.o:%.c
	$(CC) $(CFLAGS) $(CFLAGS_INC) -O -vn -c $<

$(CPM_DIR)/%.o:%.c
	$(CC) $(CFLAGS_CPM) $(CFLAGS_INC_CPM) -O -vn -o $@ -c $<
#	$(CC) $(CFLAGS_CPM) $(CFLAGS_INC_CPM) -O -vn -o $(@:.o=.c.asm) -S $<

clean:
	rm -rf $(OBJS) $(TARGET) *.c.asm *.map *.img $(CPM_DIR)

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends
