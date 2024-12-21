
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/rbuf.h>

long heap;

char buf[2048];

void test1(void)
{
    RBUF *rbuf;
    int data;

    printf("rbuf test1:");
    rbuf = rbuf_create(10);
    assert(rbuf->buf_mask == 0x0f);
    assert(rbuf_get_size(rbuf) == 0);
    rbuf_add_data(rbuf, 1);
    assert(rbuf_get_size(rbuf) == 1);
    rbuf_add_data(rbuf, 2);
    assert(rbuf_get_size(rbuf) == 2);

    data = rbuf_get_data(rbuf);
    assert(data == 1);
    assert(rbuf_get_size(rbuf) == 1);
    data = rbuf_get_data(rbuf);
    assert(data == 2);
    assert(rbuf_get_size(rbuf) == 0);

    data = rbuf_get_data(rbuf);
    assert(data == -1);
    assert(rbuf_get_size(rbuf) == 0);

    rbuf_delete(rbuf);
    printf("OK\n");
}

void test2(void)
{
    RBUF *rbuf;
    BOOL ret;

    printf("rbuf test2:");
    rbuf = rbuf_create(16);
    assert(rbuf);
    for(int i = 0; i < 16; i++) {
        ret = rbuf_add_data(rbuf, i);
        if(i == 15) {
            assert(!ret);
            assert(rbuf_get_size(rbuf) == 15);
        } else {
            assert(ret);
            assert(rbuf_get_size(rbuf) == i+1);
        }
    }
    for(int i = 0; i < 10; i++) {
        int data = rbuf_get_data(rbuf);
        assert(data == i);
    }
    for(int i = 0; i < 5; i++) {
        ret = rbuf_add_data(rbuf, i);
        assert(ret);
        assert(rbuf_get_size(rbuf) == i + 1 + 5);
    }
    rbuf_delete(rbuf);
    printf("OK\n");
}

void test3(void)
{
    RBUF *rbuf;
    BOOL bret;
    const int BUF_SIZE = 2048;
    int i;

    printf("rbuf test3:");
    rbuf = rbuf_create(BUF_SIZE);
    for(i = 0; i < BUF_SIZE; i++) {
        bret = rbuf_add_data(rbuf, (char)i);
        if(i == BUF_SIZE - 1) {
            assert(!bret);
            int size = rbuf_get_size(rbuf);
            assert(size == i);
        } else {
            assert(bret);
            int size = rbuf_get_size(rbuf);
            assert(size == i + 1);
        }
    }

    for(i = 0; i < BUF_SIZE / 2; i++) {
        int data = rbuf_get_data(rbuf);
        assert((char)i == (char)data);
        int size = rbuf_get_size(rbuf);
        assert(size == BUF_SIZE - 1 - 1 - i);
    }
    while(rbuf_get_data(rbuf) != -1);

    for(i = 0; i < BUF_SIZE-1; i++) {
        bret = rbuf_add_data(rbuf, (char)i);
        assert(bret);
        int size = rbuf_get_size(rbuf);
        assert(size == i+1);
    }
    int size = rbuf_read(rbuf, buf, 1024);
    assert(size == 1024);
    for(i = 0; i < 1024; i++) {
        assert(buf[i] == (char)i);
    }
    size = rbuf_read(rbuf, buf, 64);
    assert(size == 64);
    for(i = 1024; i < 1024 + 64; i++) {
        assert(buf[i-1024] == (char)i);
    }
    size = rbuf_read(rbuf, buf, 2048);
    assert(size == 1023 - 64);
    for(i = 1024 + 64; i < BUF_SIZE - 1; i++) {
        assert(buf[i - (1024+64)] == (char)i);
    }

    rbuf_delete(rbuf);
    printf("OK\n");
}

void test4(void)
{
    const int BUF_SIZE = 15;
    RBUF *rbuf;
    BOOL bret;
    int i;
    int ch;

    printf("rbuf test4:");
    rbuf = rbuf_create(BUF_SIZE);
    assert(rbuf);
    assert(rbuf->buf_mask == 0x0f);
    bret = rbuf_unget(rbuf, 'A');
    assert(bret);
    assert(rbuf_get_size(rbuf) == 1);
    ch = rbuf_peek_data(rbuf);
    assert(ch == 'A');
    assert(rbuf_get_size(rbuf) == 1);
    ch = rbuf_get_data(rbuf);
    assert(ch == 'A');
    assert(rbuf_get_size(rbuf) == 0);
    for(i = 0; i < BUF_SIZE; i++) {
        bret = rbuf_add_data(rbuf, 'A' + i);
        assert(bret);
        assert(rbuf_get_size(rbuf) == i + 1);
    }
    bret = rbuf_unget(rbuf, 'Z');
    assert(!bret);
    assert(rbuf_get_size(rbuf) == BUF_SIZE);

    for(i = 0; i < BUF_SIZE; i++) {
        ch = rbuf_get_data(rbuf);
        assert(ch == 'A' + i);
        assert(rbuf_get_size(rbuf) == BUF_SIZE - i - 1);
    }
    ch = rbuf_get_data(rbuf);
    assert(ch == -1);

    rbuf_delete(rbuf);

    printf("OK\n");
}

int main(void)
{
    mallinit();
    sbrk((void*)0x8000, 16 * 1024); 

    dos_scode(1);

    test1();
    test2();
    test3();
    test4();

    dos_scode(0);

    return 0;
}