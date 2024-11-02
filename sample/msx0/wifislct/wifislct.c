#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/iot.h>

long heap;

#define NODE_WIFIAPLIST             "host/wifi/aplist"
#define NODE_CONF_WIFILIST_SSID     "conf/wifi/list/%d/ssid"
#define NODE_CONF_WIFILIST_PASS     "conf/wifi/list/%d/pass"
#define NODE_CONF_WIFI_ID           "conf/wifi/id"
#define NODE_WIFI_RESTART           "host/wifi/restart"
#define NODE_CONF_SAVE              "conf/save"

int main(int argc, char *argv[])
{
    mallinit();
    sbrk(0x8000,16 * 1024);

#if __MSXDOS__ == 1
    int cmd_len = *((uint8_t *)0x0080);
    *((uint8_t *)0x0081 + cmd_len) = 0;
#endif
    if(argc == 2) {
        int16_t id = iot_geti(NODE_CONF_WIFI_ID);
        int newid = -1;
        if(strcasecmp(argv[1], "OFF") == 0) {
            newid = 0;
        } else if(strcasecmp(argv[1], "ON") == 0) {
            newid = 1;
        } else {
            int len = strlen(argv[1]);
            if(len == 1) {
                newid = argv[1][0] - 0x30;
                if(newid < 0 || newid > 3) {
                    newid = -1;
                }
            }
        }
        if(newid != -1 && id != newid) {
            iot_puti(NODE_CONF_WIFI_ID, newid);
            iot_puti(NODE_CONF_SAVE, 1);
            iot_puti(NODE_WIFI_RESTART, 1);
            printf("WiFi restart\n");
        } else if(newid == -1) {
            printf("WiFi Select ERROR\n");
        }
        return 0;
    }

    char *buf = malloc(256);

    /* Wifiアクセスポイント一覧を取得 */
    int16_t r = iot_find1(NODE_WIFIAPLIST);
    char **aplist = iot_find2(NODE_WIFIAPLIST, r);

    for(int i = 0; aplist[i]; i++) {
        for(int j = 1; j < 4; j++) {
            sprintf(buf, NODE_CONF_WIFILIST_SSID, j);
            char *ssid = iot_gets(buf);
            if(strcmp(aplist[i], ssid) == 0) {
                printf("%s\n", ssid);
                int16_t id = iot_geti(NODE_CONF_WIFI_ID);
                if(id != j) {
                    iot_puti(NODE_CONF_WIFI_ID, j);
                    iot_puti(NODE_CONF_SAVE, 1);
                    iot_puti(NODE_WIFI_RESTART, 1);
                    printf("WiFi restart\n");
                }
                break;
            }
        }
    }

    return 0;
}