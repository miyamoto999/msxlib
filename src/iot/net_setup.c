#include <msxlib/msxlib.h>
#include <msxlib/iot.h>
#include <msxlib/net.h>

/*
    ネットワーク接続設定

        hostname:ホスト名またはIPアドレス
        port:ポート番号
 */
void __LIB__ net_setup(const char *hostname, int port) __smallc
{
    iot_puts(NET_ADDR, hostname);
    iot_puti(NET_PORT, port);
}

