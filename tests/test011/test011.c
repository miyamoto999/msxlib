#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/msxdos.h>
#include <msxlib/net.h>
#include <msxlib/iot.h>
#include <msxlib/rbuf.h>
#include <time.h>

#define BUF_SIZE    200
char buf[BUF_SIZE + 1];
long heap;

int main(int argc, char *argv[])
{
    mallinit();
    sbrk((void*)0x8000,16 * 1024);

    RBUF *rbuf; 

    net_init();

    if(argc != 2) {
        fprintf(stderr, "test011 HOSTNAME\n");
        return 1;
    }

    rbuf = rbuf_create(256);
    if(!rbuf) {
        fprintf(stderr, "RBUF crate error\n");
        return 1;
    }

    for(int i = 0; i < BUF_SIZE; i++) {
        int t = i % 10;
        if(t == 0) {
            buf[i] = i / 10 + 'A';
        } else {
            buf[i] = t + '0';
        }
        buf[i + 1] = 0;
    }

    int ret = net_connect(argv[1], 3000, 30);
    if(ret != NET_ERR_NONE) {
        fprintf(stderr, "CONNECT ERR\n");
        return 1;
    }
    net_write_str(buf);

    time_t st = time(NULL);
    int total_size = 0;
    while(1) {
        int size = iot_read(rbuf, NET_MSG, buf, BUF_SIZE);
        long dt = time(NULL) - st;
        if(size == 0 && dt >= 5) {
            break;
        } else if(size != 0) {
            st = time(NULL);
            buf[size] = 0;
            puts(buf);
            total_size += size;
            if(total_size >= BUF_SIZE) {
                printf("received.\n");
                break;
            }
        }
        char ch = dos1_dirio(0xff);
        if(ch == 'q') {
            fprintf(stderr, "QUIT\n");
            break;
        } else if(ch == 'p') {
            printf("dt = %ld, time(NULL) = %ld, st = %ld, size = %d\n", dt, time(NULL), st, size);
        }
    }
    net_discconect();

    return 0;
}