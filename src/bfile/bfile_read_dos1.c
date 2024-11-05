#include <stdio.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/bfile.h>

int16_t __LIB__ bfile_read_dos1(BFILE_DOS1 *fp, void *buf, int16_t size) __smallc
{
    uint16_t read_size = 0;

    if(fp->mode == BFILE_O_WRONLY) {
        fp->err = 0xff;
        return 0;
    }
    if(fp->dirty) {
        dos1_setdta(fp->buf);
        int8_t ret = dos1_rdblk(&fp->fcb, fp->buf_size, &read_size);
        if(ret) {
            fp->eof = TRUE;
        }
        if(read_size == 0) {
            return 0;
        }
        fp->read_size = read_size;
        fp->buf_offset = 0;
        fp->dirty = FALSE;
    }
    int16_t data_size = fp->read_size - fp->buf_offset;
    if(data_size >= size) {
        memcpy(buf, &fp->buf[fp->buf_offset], size);
        fp->buf_offset += size;
        data_size = size;
    } else {
        memcpy(buf, &fp->buf[fp->buf_offset], data_size);
        fp->buf_offset = 0;
        fp->dirty = TRUE;
        data_size += bfile_read_dos1(fp, &buf[data_size], size - data_size);
    }
    return data_size;
}

