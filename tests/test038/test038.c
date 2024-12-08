#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

long heap;
#define BUF_MAX     16

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);

    uint16_t cpmver = dos1_cpmver();
    printf("cpmver:0x%04x\n", cpmver);

    return 0;
}

