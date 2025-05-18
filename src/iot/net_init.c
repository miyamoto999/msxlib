#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <msxlib/msxlib.h>
#include <msxlib/iot.h>
#include <msxlib/net.h>
#include <msxlib/msxdos.h>

char *g_iot_read_buf = NULL;

/*************************************************
    メモ：ノード名から推測するに複数のネットワークや接続先も
        想定しいるように見えるけど、そういう拡張された時に
        対応すればいいかと思う。
 *************************************************/

/*
    ネットワーク接続(TCP接続)を使うための初期化

    戻り値
        TRUE:成功
        FALSE:失敗
 */
BOOL __LIB__ net_init() __smallc
{
    g_iot_read_buf = malloc(IOT_READ_BUF_SIZE);
    if(!g_iot_read_buf) {
        return FALSE;
    }
    return TRUE;
}


