include ../inc/Makefile1.inc

TARGET=test004.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

CFLAGS_INC_DOS1+=-DAMALLOC
CFLAGS_INC_DOS2+=-DAMALLOC
CFLAGS_INC_DISK1+=-DAMALLOC
CFLAGS_INC_DISK2+=-DAMALLOC
CFLAGS_DOS1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DOS2+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK2+=-pragma-define:CRT_STACK_SIZE=128

all:$(TARGET_DOS1) $(TARGET_DISK1)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/msxlib.lib ../../libs/iot.lib
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) -L../../libs -lmsxlib -liot

$(TARGET_DOS2):$(DOS2_DIR) $(OBJS_DOS2) ../../libs/msxlib.lib ../../libs/iot.lib
	$(CC) $(CFLAGS_DOS2) -create-app -m -o $(TARGET_DOS2) $(OBJS_DOS2) -L../../libs -lmsxlib -liot

$(TARGET_DISK1):$(DISK1_DIR) $(OBJS_DISK1) ../../libs/msxlib.lib ../../libs/iot.lib
	$(CC) $(CFLAGS_DISK1) -create-app -m -o $(TARGET_DISK1) $(OBJS_DISK1) -L../../libs -lmsxlib -liot

$(TARGET_DISK2):$(DISK2_DIR) $(OBJS_DISK2) ../../libs/msxlib.lib ../../libs/iot.lib
	$(CC) $(CFLAGS_DISK2) -create-app -m -o $(TARGET_DISK2) $(OBJS_DISK2) -L../../libs -lmsxlib -liot

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:$(TARGET_DOS1)
	$(RUN) $(TARGET_DOS1)

include ../inc/Makefile2.inc
-include depends
