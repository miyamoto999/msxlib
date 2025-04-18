#include <stdio.h>
#include <string.h>
#include <msxlib/bfile.h>
#include <msxlib/msxdos.h>

/**
 * @brief ファイルからデータを読み込む
 * 
 * @param fp ファイルポインタ
 * @param buf 読み込みバッファ
 * @param size サイズ
 * @retval 読み込んだデータのサイズ
 * @retval 0 ファイルの最後に到達した 
 */
int16_t __LIB__ bfile_read_dos2(BFILE_DOS2 *fp, void *buf, int16_t size) __smallc
{
    uint16_t read_size = 0;
    if(fp->dirty) {
        int8_t ret = dos2_read(fp->handle, fp->buf, fp->buf_size, &read_size);
        if(ret == ERR_EOF) {
            fp->eof = TRUE;
        } else if(ret != 0) {
            fp->err = ret;
        }
        if(read_size == 0) {
            return 0;
        }
        fp->read_size = read_size;
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
        data_size += bfile_read_dos2(fp, &buf[data_size], size - data_size);
    }
    return data_size;
}