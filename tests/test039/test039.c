#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

/*
long heap;
*/
#define BUF_MAX     16

int main()
{
/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
*/
    printf("CurDrv:%c\n", dos1_curdrv() + 'A');
    printf("Select Drive b:\n");
    printf("0004:%02X\n", *((uint8_t *)0x0004));
    uint8_t drv_num = dos1_seldsk(1);
    printf("CurDrv:%c\n", dos1_curdrv() + 'A');
    printf("0004:%02X\n", *((uint8_t *)0x0004));
    printf("drv_max:%d\n", drv_num);

    return 0;
}

