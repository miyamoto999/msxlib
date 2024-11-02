#include <stdio.h>
#include <stdlib.h>
#include <msxlib/iot.h>
#include <string.h>

/*
    https://github.com/hra1129/for_MSX0/tree/main/sample_program/002_device/2023_05_30_1st_update_version/basicn
    こちらのコードをCで書き直したものです。
*/
char __LIB__ **iot_find2(const char *node, uint16_t r) __stdc
{
    int i;
    char **ret;

    ret = calloc(r + 1, sizeof(char*));
    if(!ret) {
        return NULL;
    }

    if(iot_node_write(node) < 0) {
        free(ret);
        return NULL;
    }

    outp(IOT_PORT1, 0xe0);
    outp(IOT_PORT1, 1);
    outp(IOT_PORT1, 0x13);      // 文字列

    outp(IOT_PORT1, 0x80);

    for(int j = 0; j < r; j++){
        int l = inp(IOT_PORT1);
        if(l == 0) {
            break;
        }
        for(i = 0; i < l; i++) {
            g_iot_common_buf[i] = inp(IOT_PORT1);
        }
        g_iot_common_buf[i] = 0;
        int len = strlen(g_iot_common_buf);
        ret[j] = malloc(len + 1);
        if(!ret[j]) {
            iot_find2_free(ret);
            return NULL;
        }
        strcpy(ret[j], g_iot_common_buf);
    }
    return ret;
}

void __LIB__ iot_find2_free(char **nodes) __smallc
{
    if(!nodes) {
        return;
    }
    for(int i = 0; nodes[i]; i++) {
        free(nodes[i]);
        nodes[i] = NULL;
    }
    free(nodes);
}