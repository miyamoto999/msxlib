/*********************************************************
 dsk1_remove.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite dsk1_remove.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>

/* ファイルの削除(FCB) */
BOOL __LIB__ dsk1_remove(const char *filename) __smallc
{
    uint8_t ret;
    MSX_FCB fcb;

    msx_fcb_init(&fcb, filename);

    ret = dsk1_fdel(&fcb);
    
    return ret == 0 ? TRUE:FALSE;
}