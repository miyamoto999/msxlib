#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>

/* _FREN用のFCB初期化 */
BOOL __LIB__ msx_fcb_init_ren(MSX_FCB *fcb, const char *old_filename, const char *new_filename) __smallc
{
    BOOL ret;

    ret = msx_fcb_init_filename(fcb, old_filename);
    if(ret) {
        ret = msx_fcb_init_filename(&fcb->ren.new_drive, new_filename);
    }
    return ret;
}