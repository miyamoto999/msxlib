#include <stdio.h>
#include <stdarg.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

#define BUF_SIZE    256

#ifdef __SCCZ80
hgohogheoghe
#endif

int __LIB__ pre_printf_sdcc(const char *fmt, ...) __z88dk_sdccdecl
{
    va_list ag;
    static char buf[BUF_SIZE];

    va_start(ag, fmt);
    int size = vsnprintf(buf, 256, fmt, ag);
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
