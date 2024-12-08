#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

long heap;

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);

    printf("Hit any key\n");
    uint8_t ch = dos1_dirin();
    printf("input:0x%x\n", ch);    

    return 0;
}

