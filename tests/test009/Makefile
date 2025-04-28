include ../inc/Makefile1.inc

TARGET=test009.com
C_SRCS=$(wildcard *.c)
ASM_SRCS=$(wildcard *.asm)

all:$(TARGET_DOS2) $(TARGET_DISK2)

$(TARGET_DOS2):$(DOS2_DIR) $(OBJS_DOS2) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_DOS2) -create-app -m -o $(TARGET_DOS2) $(OBJS_DOS2) $(LDCONFIG) -lmsxlib -ldoscall

$(TARGET_DISK2):$(DISK2_DIR) $(OBJS_DISK2) ../../libs/msxlib.lib ../../libs/doscall.lib
	$(CC) $(CFLAGS_DISK2) $(CFLAGS_DISK2) -create-app -m -o $(TARGET_DISK2) $(OBJS_DISK2) $(LDCONFIG) -lmsxlib -ldoscall

clean:
	rm -rf *.c.asm *.map *.img $(DOS1_DIR) $(DOS2_DIR) $(DISK1_DIR) $(DISK2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS2) -E -MM -w *.c > depends

tests:

include ../inc/Makefile2.inc
-include depends
