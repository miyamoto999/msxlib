DOS1_DIR=dos1
DOS2_DIR=dos2
TARGET1_DOS1=$(DOS1_DIR)/testXXa.com
TARGET1_DOS2=$(DOS2_DIR)/testXXb.com
TARGET2_DOS2=$(DOS2_DIR)/testAS.com
# TARGET3_DOS2=$(DOS2_DIR)/hello.com
LD=z88dk-z80asm
AS=z88dk-z80asm
CC=zcc
OBJS1_DOS1=$(DOS1_DIR)/testXX.o
OBJS1_DOS2=$(DOS2_DIR)/testXX.o $(DOS2_DIR)/fputc_cons_dos2.o
OBJS2_DOS2=$(DOS2_DIR)/testAS.o
# OBJS3_DOS2=$(DOS2_DIR)/hello.o
CFLAGS_INC_DOS1=-I../../include -I../common -D__MSXDOS__=1 -DAMALLOC
CFLAGS_INC_DOS2=-I../../include -I../common -D__MSXDOS__=2 -DAMALLOC
# CFLAGS=+cpm
CFLAGS_DOS1=+msx -subtype=msxdos -O2 -pragma-include:zpragma1.inc
CFLAGS_DOS2=+msx -subtype=msxdos2 -O2 -pragma-include:testXXb.inc
# CFLAGS=+msx -subtype=msxdos -compiler=sdcc
ASCONFIGS_DOS1=$(CFLAGS_INC_DOS1)
ASCONFIGS_DOS2=$(CFLAGS_INC_DOS2)

all:$(TARGET1_DOS1) $(TARGET1_DOS2) $(TARGET2_DOS2)

$(TARGET1_DOS1):$(DOS1_DIR) $(OBJS1_DOS1) ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS1) -create-app -m -o $(TARGET1_DOS1) $(OBJS1_DOS1) -L../../libs -ldoscall -lm

$(TARGET1_DOS2):$(DOS2_DIR) $(OBJS1_DOS2) ../../libs/doscall.lib
	$(CC) $(CFLAGS_DOS2) -create-app -m -o $(TARGET1_DOS2) $(OBJS1_DOS2) -L../../libs -ldoscall -lm

$(TARGET2_DOS2):$(DOS2_DIR) $(OBJS2_DOS2)
	$(CC) $(CFLAGS_DOS2) --no-crt -create-app -m -o $(TARGET2_DOS2) $(OBJS2_DOS2)

# $(TARGET3_DOS2):$(DOS2_DIR) $(OBJS3_DOS2)
# 	$(CC) $(CFLAGS_DOS2) -create-app -m -o $(TARGET3_DOS2) $(OBJS3_DOS2) -lm

$(DOS1_DIR):
	mkdir -p $(DOS1_DIR)

$(DOS2_DIR):
	mkdir -p $(DOS2_DIR)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS_DOS1) $<

$(DOS1_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS1) $(CFLAGS_INC_DOS1) -vn -o $@ -c $<

$(DOS2_DIR)/%.o:%.c
	$(CC) $(CFLAGS_DOS2) $(CFLAGS_INC_DOS2) -vn -o $@ -c $<

$(DOS1_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS1) -o=$@ $<

$(DOS2_DIR)/%.o:%.asm
	$(AS) $(ASCONFIGS_DOS2) -o=$@ $<

clean:
	rm -rf *.c.asm *.map *.img *.msx $(DOS1_DIR) $(DOS2_DIR)

depend:
	gcc $(CFLAGS_INC_DOS1) -E -MM -w *.c > depends

tests:$(TARGET)
#	emmy80 $(TARGET)

-include depends
