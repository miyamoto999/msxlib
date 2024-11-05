#include <stdio.h>
#include <string.h>
#include <msxlib/bfile.h>
#include <msxlib/msxdos.h>

BFILE_DOS2 __LIB__ *bfile_open_dos2(const char *filename, uint8_t mode, int16_t buf_size) __smallc
{
    uint8_t dos2_open_mode = 0;

    BFILE_DOS2 *fp = malloc(sizeof(BFILE_DOS2));
    if(!fp) {
        return NULL;
    }
    memset(fp, 0, sizeof(BFILE_DOS2));

    fp->buf_size = buf_size > 0 ? buf_size:DEF_BUF_SIZE;
    fp->buf = malloc(fp->buf_size);
    if(!fp->buf) {
        free(fp);
        return NULL;
    }
    switch(mode) {
        case BFILE_O_RDONLY:
            dos2_open_mode = FILE_MODE_READ_ONLY | FILE_MODE_INHELITANCE;
            break;
        case BFILE_O_WRONLY:
            dos2_open_mode = FILE_MODE_WRITE_ONLY | FILE_MODE_INHELITANCE;
            break;
        case BFILE_O_RDWR:
            dos2_open_mode = FILE_MODE_READ_WRITE | FILE_MODE_INHELITANCE;
            break;
    }

    uint8_t err = dos2_open(filename, dos2_open_mode, &(fp->handle));
    if(err) {
        free(fp->buf);
        free(fp);
        return NULL;
    }
    fp->mode = mode;
    fp->dirty = TRUE;
    fp->update = FALSE;

    return fp;
}
