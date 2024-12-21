#include <stdlib.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/rbuf.h>

RBUF __LIB__ *rbuf_create(int size) __smallc
{
    RBUF *rbuf;

    rbuf = malloc(sizeof(RBUF));
    if(!rbuf) {
        return NULL;
    }
    // ちょうどいいサイズにする。
    int s = size - 1;
    s |= s >> 1;
    s |= s >> 2;
    s |= s >> 4;
    s |= s >> 8;

    rbuf->buf_mask = s;
    s++;

    rbuf->buf = malloc(s);
    if(!rbuf->buf) {
        free(rbuf);
        return NULL;
    }

    rbuf->read_idx = 0;
    rbuf->write_idx = 0;

    return rbuf;
}

void __LIB__ rbuf_delete(RBUF *rbuf)
{
    if(rbuf->buf) {
        free(rbuf->buf);
        rbuf->buf = NULL;
    }
    free(rbuf);
}

int __LIB__ rbuf_peek_data(RBUF *rbuf)
{
    if(rbuf->read_idx == rbuf->write_idx) {
        return -1;
    }
    int ret = rbuf->buf[rbuf->read_idx];
    return ret & 0xff;
}

BOOL __LIB__ rbuf_unget(RBUF *rbuf, char ch) __smallc
{
    int idx;

    idx = (rbuf->read_idx - 1) & rbuf->buf_mask;
    if(rbuf->write_idx == idx) {
        return FALSE;
    }
    rbuf->buf[idx] = ch;
    rbuf->read_idx = idx;
    return TRUE;
}
