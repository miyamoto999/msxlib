include ../inc/Makefile1.inc

TARGET=test022.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

TARGET2=test022x.com
OBJS2=test022x.o

CFLAGS_INC_DOS1+=-DAMALLOC
CFLAGS_INC_DOS2+=-DAMALLOC
CFLAGS_INC_DISK1+=-DAMALLOC
CFLAGS_INC_DISK2+=-DAMALLOC
CFLAGS_DOS1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DOS2+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK1+=-pragma-define:CRT_STACK_SIZE=128
CFLAGS_DISK2+=-pragma-define:CRT_STACK_SIZE=128

all:$(TARGET_DOS1) $(TARGET_DISK1) $(TARGET2)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) $(LDCONFIG) -lmsxlib

$(TARGET_DISK1):$(DISK1_DIR) $(OBJS_DISK1) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DISK1) $(CFLAGS_INC_DISK1) -create-app -m -o $(TARGET_DISK1) $(OBJS_DISK1) $(LDCONFIG) -lmsxlib

$(TARGET2):$(OBJS2) ../../libs/msxlib.lib
	$(CC) $(CFLAGS_DOS1) --no-crt -create-app -m -o $(TARGET2) $(ASCONFIGS) $(OBJS2) -L../../libs -lmsxlib

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR) $(TARGET2) $(OBJS2)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

test022x.o:test022x.asm ../../include/msxlib/asm/msxdos.inc

tests:$(TARGET_DOS1)
	$(RUN) $(TARGET_DOS1)

include ../inc/Makefile2.inc
-include depends
