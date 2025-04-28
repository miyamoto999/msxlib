TARGET=common.lib
CC=zcc
LD=z88dk-z80asm

C_SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(C_SRCS))

CFLAGS_INC=-I../../include
CFLAGS=+msx -O2

all:$(TARGET)

$(TARGET):$(OBJS)
	$(LD) -x$(TARGET) $(OBJS)

.SUFFIXES: .asm .o
.asm.o:
	$(AS) $(ASCONFIGS) $<

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -vn -c $<
#	$(CC) $(CFLAGS) --no-crt -S $<

clean:
	rm -f $(OBJS) $(TARGET)

depend:
	gcc $(CFLAGS_INC) -E -MM -w *.c > depends

tests:

-include depends