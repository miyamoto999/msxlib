#include <stdio.h>
#include <stdarg.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

#define BUF_SIZE    256

int __LIB__ pre_printf_scc(const char *fmt, ...) __smallc
{
    va_list ag;
    static char buf[BUF_SIZE];

    int a = getarg();
    ag = ((a - 1) << 1) - 2 + &fmt;
    char *format = *((int*)(((a - 1) << 1) + &fmt));
    int size = vsnprintf(buf, 256, format, ag);
    va_end(ag);

    if(size < 0) {
        return size;
    }

    for(int i = 0; buf[i]; i++) {
        dos1_dirio(buf[i]);
        if(buf[i] == 0x0a) {
            dos1_dirio(0x0d);
        }
    }

    return size;
}
