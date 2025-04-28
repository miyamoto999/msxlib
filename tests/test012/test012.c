#include <stdio.h>
#include <stdlib.h>
#include <msxlib/msxlib.h>
#include <msxlib/bfile.h>

/*
long heap;
*/

int main(void)
{
/*
    mallinit();
    sbrk((void*)0xd000, 1024);
*/
    BFILE *bfp = bfile_create("test.txt", 512);
    if(!bfp) {
        fprintf(stderr, "bfile_create ERROR\n");
        return 1;
    }

    for(int i = 0; i < 100; i++) {
        char ch = (i % 10) + '0';
        bfile_write(bfp, &ch, 1);
    }
    bfile_close(bfp);

    return 0;
}