#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <msxlib/msxlib.h>
#include <msxlib/fcb.h>

/*
    FCBにファイル名を設定する。

        fcb:FCBのアドレス
        filename:ファイル名

    戻り値
        TRUE:成功
        FALSE:失敗
 */
BOOL __LIB__ msx_fcb_init(MSX_FCB *fcb, const char *filename) __smallc
{
    memset(fcb, 0, sizeof(MSX_FCB));

    return msx_fcb_init_filename(fcb, filename);
}
