/*********************************************************
 dsk1_rename.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite dsk1_rename.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>

/* ファイル名の変更(FCB) */
BOOL __LIB__ dsk1_rename(const char *oldFilename, const char *newFilename) __smallc
{
    MSX_FCB fcb;
    BOOL ret;
    uint8_t ret8;

    memset(&fcb, 0, sizeof(MSX_FCB));
    ret = msx_fcb_init_ren(&fcb, oldFilename, newFilename);    
    if(!ret) {
        return ret;
    }
    ret8 = dsk1_fren(&fcb);

    return ret8 == 0 ? TRUE:FALSE;
}