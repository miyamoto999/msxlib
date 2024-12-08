#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

long heap;
#define BUF_MAX     16

char buf[BUF_MAX + 2];

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);

    printf("Line input\n");
    buf[0] = BUF_MAX;
    dos1_bufin(buf);
    printf("\n");
    for(int i = 0; i < BUF_MAX; i++) {
        printf("%02x ", buf[i] & 0xff);
    }
    printf("\n");

    return 0;
}

