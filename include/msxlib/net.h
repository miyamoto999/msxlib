#ifndef __NET_H__
#define __NET_H__

#include <msxlib/msxlib.h>
#include <msxlib/rbuf.h>

#define NET_IF      "msx/me/if/NET0/"
#define NET_ADDR    "msx/me/if/NET0/conf/addr"
#define NET_PORT    "msx/me/if/NET0/conf/port"
#define NET_CONNECT "msx/me/if/NET0/connect"
#define NET_MSG     "msx/me/if/NET0/msg"

#define NET_ERR_NONE        0
#define NET_ERR_TIMEOUT     1
#define NET_ERR_ABORT       2

void __LIB__ net_setup(const char *hostname, int port) __smallc;
int __LIB__ net_connect(const char *hostname, int port, int time_out) __smallc;
#define net_start_connect()       iot_puti(NET_CONNECT, 1)
// BOOL net_is_connected();
#define net_is_connected()      iot_geti(NET_CONNECT)
// void net_discconect();
#define net_discconect()        iot_puti(NET_CONNECT, 0)

// void net_write_str(const char *msg);
#define net_write_str(msg)          iot_puts(NET_MSG, msg)

BOOL __LIB__ net_init(void) __smallc;
char __LIB__ *net_readline(RBUF *rbuf) __smallc;

#define IOT_READ_BUF_SIZE   256
extern char *g_iot_read_buf;

#endif