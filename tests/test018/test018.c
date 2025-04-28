#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>

static char buf[128];

/*
long heap;
*/

static int test1(void)
{
    MSX_FIB fib;
    BOOL bret;
    char filename[FCB_NAME_SIZE + FCB_EXT_SIZE + 1];

    uint8_t ret = dos2_ffirst("t*.*", NULL, 0, &fib);
    assert(ret != ERR_NOFIL);

    while(ret == 0) {
        puts(fib.filename);
        
        ret = dos2_fnext(&fib);
    };

    return 0;
}

int main(void)
{
/*
    mallinit();
#ifdef __DSKBAS__
    sbrk((void*)0xc000, 1024); 
#else
    sbrk((void*)0x8000, 8 * 1024); 
#endif
*/
#ifndef __DSKBAS__
    dos_scode(1);
#endif

#if __DSKBAS__ == 1
    puts("DSKBAS1 Version");
#elif __DSKBAS__ == 2
    puts("DSKBAS2 Version");
#elif defined(__CPM__)
    puts("CP/M Version");
#elif __MSXDOS__ == 1
    puts("DOS1 Version");
#elif __MSXDOS__ == 2
    puts("DOS2 Version");
#endif

    test1();

#ifndef __DSKBAS__
    dos_scode(0);
#endif

    return 0;
}