/*********************************************************
 bfile/bfile_flush_dsk1.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_flush_dsk1.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <msxlib/bfile.h>

BOOL __LIB__ bfile_flush_dsk1(BFILE_DOS1 *fp) __smallc
{
    if(fp->update) {
        dsk1_setdta(fp->buf);
        int8_t err = dsk1_wrblk(&fp->fcb, fp->buf_offset);
        if(err) {
            fp->err = err;
            return FALSE;
        }
        fp->buf_offset = 0;
        fp->dirty = TRUE;
        fp->update = FALSE;
    }

    return TRUE;
}