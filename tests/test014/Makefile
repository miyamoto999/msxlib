include ../inc/Makefile1.inc

TARGET=test014.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

SDCC1_DIR=./sdcc1
TARGET_SDCC1=$(SDCC1_DIR)/$(TARGET)
OBJS_SDCC1=$(patsubst %.c, $(SDCC1_DIR)/%.o, $(C_SRCS)) $(patsubst %.asm, $(DOS1_DIR)/%.o, $(ASM_SRCS))
CFLAGS_INC_SDCC1=-I../../include -I../../crt0 -I../common -D__MSXDOS__=1
CFLAGS_SDCC1=+msx -subtype=msxdos -compiler=sdcc -create-app -crt0=../../crt0/msx_crt0.asm -m -pragma-include:../../pragma/msxdos1.def

all:$(TARGET_DOS1) $(TARGET_SDCC1)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/bios.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) -L../../libs -lbios -lmsxlib

$(TARGET_SDCC1):$(SDCC1_DIR) $(OBJS_SDCC1) ../../libs/bios.lib ../../libs/msxlib.lib
	$(CC) $(CFLAGS_SDCC1) $(CFLAGS_INC_SDCC1) -create-app -m -o $(TARGET_SDCC1) $(OBJS_SDCC1) -L../../libs -lbios -lmsxlib

$(SDCC1_DIR):
	mkdir -p $(SDCC1_DIR)

$(SDCC1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_SDCC1) $(CFLAGS_INC_SDCC1) -vn -o $@ -c $<

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR) $(SDCC1_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:

include ../inc/Makefile2.inc
-include depends
