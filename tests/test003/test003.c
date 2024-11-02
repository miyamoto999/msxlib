#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>
#include <msxlib/msxlib.h>
#include <msxlib/iot.h>

long heap;

#define NODE_WIFI       "host/wifi/aplist"
#define NODE_BATTERY    "host/battery/level"
#define NODE_IP         "host/ip"

int main(void)
{
    mallinit();
    sbrk((void*)0xc000,1024); 

#ifdef __MSXDOS__
    uint16_t *addr = (uint16_t*)0x0006;
    uint16_t tpa_last = *addr;
    printf("TPA LAST:0x%04x\n", tpa_last);
#endif

    // Wifiサーチ
    uint16_t count = iot_find1(NODE_WIFI);
    printf("aplist count=%u\n", count);

    char **datas = iot_find2(NODE_WIFI, count);
    for(int i = 0; datas[i] != NULL; i++) {
        printf("%d:0x%x:\"%s\"\n", i, datas[i], datas[i]);
    }

    // バッテリー残量
    uint16_t battery = iot_geti(NODE_BATTERY);
    printf("Battery:%u\n", battery);

    // ipアドレス
    char *str = iot_gets(NODE_IP);
    printf("IP Addr.:%s\n", str);

    return 0;
}