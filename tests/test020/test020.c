#include <stdio.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>

void dump(void *addr, int size)
{
    unsigned char *p = (unsigned char*)addr;

    for(int i = 0; i < size; i++, p++) {
        printf("%02X ", *p);
    }
    printf("\n");
}

int main()
{
    MSX_FCB fcb;

    msx_fcb_init(&fcb, "abc.txt");
    for(int i = 0; i < sizeof(fcb); i++) {
        printf("%02x ", i);
    }
    printf("\n");
    dump(&fcb, sizeof(fcb));
    dos1_fmake(&fcb);
    dump(&fcb, sizeof(fcb));
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, "test020.com");
    dos1_fopen(&fcb);
    dump(&fcb, sizeof(fcb));
    dos1_fclose(&fcb);

    return 0;
}