#include <msxlib/bfile.h>
#include <msxlib/msxdos.h>

/**
 * @brief ファイルのシーク
 * 
 * @param fp ファイルポインタ
 * @param offset オフセット
 * @param whence 最初の位置
 * @return int32_t 新しい位置
 */
int32_t __LIB__ bfile_fseek_dos2(BFILE_DOS2 *fp, int32_t offset, int whence) __smallc
{
    uint8_t err;

    if(fp->update) {
        if(!bfile_flush_dos2(fp)) {
            return 0;
        }
    }
    err = dos2_seek(fp->handle, &offset, whence);
    if(err != 0) {
        fp->err = err;
        offset = 0;
    }
    fp->dirty = TRUE;
    return offset;
}