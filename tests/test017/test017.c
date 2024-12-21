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

long heap;

static int test1(void)
{
    MSX_FCB fcb, *fcb2;
    BOOL bret;
    char filename[FCB_NAME_SIZE + FCB_EXT_SIZE + 1];

    bret = msx_fcb_init(&fcb, "t*.*");
    assert(bret);

    dos1_setdta(buf);

    uint8_t ret = dos1_sfirst(&fcb);
    assert(ret == 0);
    fcb2 = (MSX_FCB*)buf;

    while(ret == 0) {
        memcpy(filename, fcb2->v1.name, FCB_NAME_SIZE + FCB_EXT_SIZE);
        filename[FCB_NAME_SIZE + FCB_EXT_SIZE] = 0;
        puts(filename);
        
        ret = dos1_snext();
    };

    return 0;
}

int main(void)
{
    mallinit();
#ifdef __DSKBAS__
    sbrk((void*)0xc000, 1024); 
#else
    sbrk((void*)0x8000, 8 * 1024); 
#endif
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