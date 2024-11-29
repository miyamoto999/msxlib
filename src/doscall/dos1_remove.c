#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>

/* ファイルの削除(FCB) */
BOOL __LIB__ dos1_remove(const char *filename) __smallc
{
    uint8_t ret;
    MSX_FCB fcb;

    msx_fcb_init(&fcb, filename);

    ret = dos1_fdel(&fcb);
    
    return ret == 0 ? TRUE:FALSE;
}