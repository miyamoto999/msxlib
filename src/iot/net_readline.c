#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/net.h>
#include <msxlib/iot.h>

/*
    接続先からデータを1バイト取得

        rbuf:リングバッファ

    戻り値
        -1以外:データ
        -1:データなし
 */
static int read_char(RBUF *rbuf) __smallc
{
    char data;
    int size;

    size = iot_read(rbuf, NET_MSG, &data, 1);
    if(size == 0) {
        return -1;
    }
    return data & 0xff;
}

/*
    ネットワーク(TCP接続)から1行取得

        rbuf:リングバッファ

    戻り値
        1行分の受信したデータ(LFまたはCRLFまでのデータ)
 */
char __LIB__ *net_readline(RBUF *rbuf) __smallc
{
    int size, idx;
    BOOL crflag = FALSE;

    idx = 0;

    while(1)
    {
        if(IOT_READ_BUF_SIZE - 1 == idx) {
            g_iot_read_buf[idx] = 0;
            break;
        }
        BOOL is_connected = iot_geti(NET_CONNECT);
        int ch = read_char(rbuf);
        if(ch == -1 && is_connected) {
            continue;
        } else if(ch == -1) {
            break;
        } else if(ch == 0x0a) {
            if(idx > 0 && g_iot_read_buf[idx - 1] == '\x0d') {
                g_iot_read_buf[idx - 1] = 0;
            } else {
                g_iot_read_buf[idx] = 0;
                idx++;
            }
            crflag = TRUE;
            break;
        } else {
            g_iot_read_buf[idx] = ch;
            idx++;
        }
    }

    if(!crflag) {
        g_iot_read_buf[idx] = 0;
    }
    return g_iot_read_buf;
}
