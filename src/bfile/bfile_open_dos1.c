#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/bfile.h>

BFILE_DOS1 __LIB__ *bfile_open_dos1(const char *filename, uint8_t mode, int16_t buf_size) __smallc
{
    BFILE_DOS1 *fp = NULL;

    if(mode != BFILE_O_RDONLY && mode != BFILE_O_WRONLY && mode != BFILE_O_RDWR) {
        return NULL;
    }

    fp = bfile_malloc_dos1(filename, buf_size);
    if(!fp) {
        return NULL;
    }
    uint8_t err = dos1_fopen(&fp->fcb);
    if(err) {
        free(fp->buf);
        free(fp);
        return NULL;
    }
    fp->fcb.v1.record_size = 1;
    fp->fcb.v1.random_record = 0;
    fp->mode = mode;
    fp->update = FALSE;

    return fp;
}
