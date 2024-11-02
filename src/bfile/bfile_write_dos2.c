#include <string.h>
#include <msxlib/bfile.h>

/*
  ファイル書き込み

    fp:BFILE_DOS2構造体のポインタ
    buf:書き込むデータへのポインタ
    size:データサイズ

  戻り値
      書き込んだサイズ
*/
int16_t __LIB__ bfile_write_dos2(BFILE_DOS2 *fp, const void *buf, int16_t size) __smallc
{
    uint16_t tmp_size;
    uint8_t err;

    if(fp->err) {
        return 0;
    }

    if(size >= fp->buf_size) {
        if(fp->buf_offset != 0) {
            err = dos2_write(fp->handle, fp->buf, fp->buf_offset, &tmp_size);
            if(err) {
                fp->err = err;
                return 0;
            }
            fp->buf_offset = 0;
        }
        err = dos2_write(fp->handle, buf, size, &tmp_size);
        if(err) {
            fp->err = err;
            return 0;
        }
    } else {
        int copy_size, rest_size = size;
        int idx = 0;
        while(rest_size != 0) {
            if(fp->buf_size - fp->buf_offset < rest_size) {
                copy_size = fp->buf_size - fp->buf_offset;
                rest_size -= copy_size;
            } else {
                copy_size = rest_size;
                rest_size = 0;
            }
            memcpy(&fp->buf[fp->buf_offset], &buf[idx], copy_size);
            fp->buf_offset += copy_size;
            idx += copy_size;
            if(fp->buf_offset == fp->buf_size) {
                err = dos2_write(fp->handle, fp->buf, fp->buf_offset, &tmp_size);
                if(err) {
                    fp->err = err;
                    return 0;
                }
                fp->buf_offset = 0;
            }
        }
    }
    return size;
}

