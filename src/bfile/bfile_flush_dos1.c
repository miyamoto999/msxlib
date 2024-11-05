#include <msxlib/bfile.h>

BOOL __LIB__ bfile_flush_dos1(BFILE_DOS1 *fp) __smallc
{
    if(fp->update) {
        dos1_setdta(fp->buf);
        int8_t err = dos1_wrblk(&fp->fcb, fp->buf_offset);
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