include ../inc/Makefile1.inc

TARGET=test055.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

GCC_DIR=gcc
TARGET_GCC=$(patsubst %.com, $(GCC_DIR)/%, $(TARGET))
OBJS_GCC=$(patsubst %.c, $(GCC_DIR)/%.o, $(C_SRCS))
CFLAGS_INC_GCC=$(CFLAGS_INC_DOS2)


CFLAGS_INC_DOS1+=-DAMALLOC
CFLAGS_INC_DOS2+=-DAMALLOC
CFLAGS_INC_DISK1+=-DAMALLOC
CFLAGS_INC_DISK2+=-DAMALLOC
CFLAGS_DOS1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DOS2+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK2+=-pragma-define:CRT_STACK_SIZE=128

all:$(TARGET_DOS1) $(TARGET_DISK1) $(TARGET_DOS2) $(TARGET_DISK2) $(TARGET_GCC)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) $(LDCONFIG) -lmsxlib

$(TARGET_DOS2):$(DOS2_DIR) $(OBJS_DOS2) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -create-app -m -o $(TARGET_DOS2) $(OBJS_DOS2) $(LDCONFIG) -lmsxlib

$(TARGET_DISK1):$(DISK1_DIR) $(OBJS_DISK1) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DISK1) $(CFLAGS_INC_DISK1) -create-app -m -o $(TARGET_DISK1) $(OBJS_DISK1) $(LDCONFIG) -lmsxlib

$(TARGET_DISK2):$(DISK2_DIR) $(OBJS_DISK2) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DISK2) $(CFLAGS_INC_DISK2) -create-app -m -o $(TARGET_DISK2) $(OBJS_DISK2) $(LDCONFIG) -lmsxlib

$(TARGET_GCC):$(GCC_DIR) $(OBJS_GCC)
	gcc -o $(TARGET_GCC) $(OBJS_GCC)

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR) $(GCC_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:$(TARGET_DOS1)
	$(RUN) $(TARGET_DOS1)

$(GCC_DIR):
	mkdir -p $(GCC_DIR)

$(GCC_DIR)/%.o: %.c
	gcc $(CFLAGS_INC_GCC) -o $@ -c $<

include ../inc/Makefile2.inc
-include depends
