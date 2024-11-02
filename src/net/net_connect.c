#include <stdio.h>
#include <time.h>
#include <msxlib/net.h>
#include <msxlib/iot.h>
#include <msxlib/msxdos.h>

/*
    ネットワーク接続(TCP接続)
    
        hostname:ホスト名またはIPアドレス
        port:ポート番号
        time_out:タイムアウト(sec)

    戻り値
        NET_ERR_NONE:成功
        その他：失敗
 */
int __LIB__ net_connect(const char *hostname, int port, int time_out) __smallc
{
    time_t st = time(NULL);

    net_setup(hostname, port);
    iot_puti(NET_CONNECT, 1);

    while(!net_is_connected()) {
        if(time(NULL) - st >= time_out) {
            return NET_ERR_TIMEOUT;
        }
        uint8_t key = dos1_dirio(0xff);
        if(key == 0x03 || key == 0xd3) {      /* DOS2のdos2_defab(アボート処理ルーチンの定義)で
                                                    CTRL-STOPで勝手に終了しないようにしている場合、
                                                    CTRL-STOPを押すと0xd3が返ってくるが、ドキュメントに
                                                    それっぽい記述が見つからない。けど、telnetでCtrl-Cを押すと
                                                    Ctrl-STOPを押したことになるようなので0xd3でもNET_ERR_ABORT
                                                    するようにした。
                                                    なお、DOS1ではCTRL-STOPを押すと0x03が返ってくる。
                                                    */
            return NET_ERR_ABORT;
        }
    }
    return NET_ERR_NONE;
}
