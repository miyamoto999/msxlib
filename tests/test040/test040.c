#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

/*
long heap;
*/

char buf[128];

void print_usage()
{
    printf("test040 DISKDRIVE\n");
    printf("  DISKDRIVE A~D\n");
}

int main(int argc, char *argv[])
{
    char filename[FCB_NAME_SIZE + FCB_EXT_SIZE + 1];

/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
*/

    if(argc != 2) {
        print_usage();
        return 1;
    }

    char drv = toupper(argv[1][0]) - 'A';
    if(drv < 0 || drv > 4) {
        print_usage();
        return 1;
    }
    
    MSX_FCB fcb, *fcb2;

    msx_fcb_init(&fcb, "*.*");

    fcb.v1.drive = drv + 1;

    dos1_setdta(buf);
    fcb2 = (MSX_FCB*)buf;

    uint8_t ret = dos1_sfirst(&fcb);
    while(ret == 0) {
        memcpy(filename, fcb2->v1.name, FCB_NAME_SIZE + FCB_EXT_SIZE);
        filename[FCB_NAME_SIZE + FCB_EXT_SIZE] = 0;
        puts(filename);
        
        ret = dos1_snext();
    }
    return 0;
}