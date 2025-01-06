#include <msxlib/msxlib.h>
#include <msxlib/iot.h>
#include <string.h>

/**
 * @brief MSX0のIOTノードから実数値を取得する。
 * @details
 *      指定したノードから実数値(MSXのBCD実数形式)を取得する。
 * 
 * @param node IOTノード
 * @param bcdf BCD実数形式の値を格納するバッファ(BCDF_DOUBLE_SIZEサイズ必要)
 * @return BOOL TRUE:成功 FALSE:失敗(ノードが実数値を返さないノードの場合)
 */
BOOL __LIB__ iot_getbcdf(const char *node, char *bcdf) __smallc
{
    iot_node_write(node);

    outp(IOT_PORT1, 0xe0);
    outp(IOT_PORT1, 1);
    outp(IOT_PORT1, 1);
    outp(IOT_PORT1, 0x80);

    int r = inp(IOT_PORT1);

    if(r != 4 && r != 8) {
        return FALSE;
    }

    memset(bcdf, 0, BCDF_DOUBLE_SIZE);
    for(int i = 0; i < r; i++) {
        bcdf[i] = inp(IOT_PORT1);
    }

    return TRUE;
}