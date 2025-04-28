include ../inc/Makefile1.inc

TARGET=test039.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

all:$(TARGET_DOS1) $(TARGET_DISK1)

$(TARGET_DOS1):$(DOS1_DIR) $(OBJS_DOS1) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS1) -create-app -m -o $(TARGET_DOS1) $(OBJS_DOS1) $(LDCONFIG) -lmsxlib -ldoscall

$(TARGET_DISK1):$(DISK1_DIR) $(OBJS_DISK1) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DISK1) -create-app -m -o $(TARGET_DISK1) $(OBJS_DISK1) $(LDCONFIG) -lmsxlib -ldoscall

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:

include ../inc/Makefile2.inc
-include depends
