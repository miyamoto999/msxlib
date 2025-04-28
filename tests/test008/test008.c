#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <msxlib/iot.h>

int test1(void)
{
    printf("iot_node_write err test:");
    int8_t r = iot_node_write("hoge");
    assert(r < 0);
    printf("OK\n");
    return 0;
}

int test2(void)
{
    printf("iot_node_write test1:");
    int8_t r = iot_node_write("host");
    assert(r == 0);
    printf("OK\n");
    return 0;
}

int test3(void)
{
    printf("iot_node_write test2:");
    int8_t r = iot_node_write("host/battery");
    assert(r == 0);
    printf("OK\n");
    return 0;
}

int main(void)
{
    test1();
    test2();
    test3();

    return 0;
}