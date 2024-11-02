#ifndef __RBUF_H__
#define __RBUF_H__

#include <msxlib/msxlib.h>

typedef struct _rbuf {
    char *buf;
    int read_idx;
    int write_idx;
    int buf_mask;
} RBUF;

RBUF __LIB__ *rbuf_create(int size) __smallc;
int __LIB__ rbuf_get_size(const RBUF *rbuf) __smallc;
BOOL __LIB__ rbuf_add_data(RBUF *rbuf, const char data) __smallc;
int __LIB__ rbuf_get_data(RBUF *rbuf) __smallc;
int __LIB__ rbuf_peek_data(RBUF *rbuf) __smallc;
int __LIB__ rbuf_unget(RBUF *rbuf) __smallc;
int __LIB__ rbuf_read(RBUF *rbuf, char *buf, int size) __smallc;
void __LIB__ rbuf_delete(RBUF *rbuf) __smallc;

#endif