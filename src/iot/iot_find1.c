#include <stdio.h>
#include <msxlib/iot.h>

/*
    https://github.com/hra1129/for_MSX0/tree/main/sample_program/002_device/2023_05_30_1st_update_version/basicn
    こちらのコードをCで書き直したものです。
*/

int16_t __LIB__ iot_find1(const char *node) __smallc
{
    if(iot_node_write(node) < 0) {
        return -1;
    }

    outp(IOT_PORT1, 0xe0);
    outp(IOT_PORT1, 1);
    outp(IOT_PORT1, 0x11);          // 整数値
    outp(IOT_PORT1, 0x80);

    uint16_t ret = 0;

    int r = inp(IOT_PORT1);

    r = inp(IOT_PORT1);
    ret = r;
    r = inp(IOT_PORT1);
    ret |= (r << 8);

    return ret;
}
