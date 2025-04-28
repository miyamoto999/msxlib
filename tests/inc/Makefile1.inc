DOS1_DIR=dos1
DOS2_DIR=dos2
DISK1_DIR=disk1
DISK2_DIR=disk2
TARGET_DOS1=$(DOS1_DIR)/$(TARGET)
TARGET_DOS2=$(DOS2_DIR)/$(TARGET)
TARGET_DISK1=$(patsubst %.com, $(DISK1_DIR)/%.msx, $(TARGET))
TARGET_DISK2=$(patsubst %.com, $(DISK2_DIR)/%.msx, $(TARGET))
LD=zcc
AS=z88dk-z80asm
CC=zcc
OBJS_DOS1=$(patsubst %.c, $(DOS1_DIR)/%.o, $(C_SRCS)) $(patsubst %.asm, $(DOS1_DIR)/%.o, $(ASM_SRCS))
OBJS_DOS2=$(patsubst %.c, $(DOS2_DIR)/%.o, $(C_SRCS)) $(patsubst %.asm, $(DOS2_DIR)/%.o, $(ASM_SRCS))
OBJS_DISK1=$(patsubst %.c, $(DISK1_DIR)/%.o, $(C_SRCS)) $(patsubst %.asm, $(DISK1_DIR)/%.o, $(ASM_SRCS))
OBJS_DISK2=$(patsubst %.c, $(DISK2_DIR)/%.o, $(C_SRCS)) $(patsubst %.asm, $(DISK2_DIR)/%.o, $(ASM_SRCS))
CFLAGS_INC_DOS1=-I../../include -I../common -D__MSXDOS__=1
CFLAGS_INC_DOS2=-I../../include -I../common -D__MSXDOS__=2
CFLAGS_INC_DISK1=-I../../include -I../common -D__DSKBAS__=1
CFLAGS_INC_DISK2=-I../../include -I../common -D__DSKBAS__=2
CFLAGS_DOS1=+msx -subtype=msxdos -create-app -m -pragma-include:../../pragma/msxdos1.def
CFLAGS_DOS2=+msx -subtype=msxdos2 -create-app -m -pragma-include:../../pragma/msxdos1.def
CFLAGS_DISK1=+msx -subtype=diskio --msxdos1 -O2 -pragma-include:../../pragma/disk1.def
CFLAGS_DISK2=+msx -subtype=diskio --msxdos2 -O2 -pragma-include:../../pragma/disk2.def
ASCONFIGS_DOS1=$(CFLAGS_INC_DOS1)
ASCONFIGS_DOS2=$(CFLAGS_INC_DOS2)
ASCONFIGS_DISK1=$(CFLAGS_INC_DISK1)
ASCONFIGS_DISK2=$(CFLAGS_INC_DISK2)
LDCONFIG=-L../../libs -L../common
RUN=emmy80


