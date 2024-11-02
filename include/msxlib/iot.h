#ifndef __IOT_H__
#define __IOT_H__

#include <msxlib/msxlib.h>
#include <msxlib/msxbios.h>
#include <msxlib/rbuf.h>
#include <msxlib/iotaddr.h>

BOOL __LIB__ iot_puts(const char *node, const char *val) __smallc;
BOOL __LIB__ iot_puti(const char *node, const int val) __smallc;
short __LIB__ iot_geti(const char *node) __smallc;
char __LIB__ *iot_gets(const char *node) __smallc;
int8_t __LIB__ iot_node_write(const char *node) __smallc;

int __LIB__ iot_read(RBUF *rbuf, const char *node, char *buf, int size) __smallc;
void __LIB__ iot_write(const char *node, char *buf, uint8_t size) __smallc;

// int iot_read_1(RBUF *rbuf, const char *node, char *buf, int size);

int16_t __LIB__ iot_find1(const char *node) __smallc;
char __LIB__ **iot_find2(const char *node, uint16_t r) __stdc;
void __LIB__ iot_find2_free(char **nodes) __smallc;

#define IOT_COMMON_BUF_SIZE 256
extern char g_iot_common_buf[IOT_COMMON_BUF_SIZE];

#endif