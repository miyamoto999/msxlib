#include <msxlib/bfile.h>

BOOL __LIB__ bfile_flush_dos2(BFILE_DOS2 *fp) __smallc
{
    if(fp->update) {
        uint16_t tmp_size;
        uint8_t err = dos2_write(fp->handle, fp->buf, fp->buf_offset, &tmp_size);
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