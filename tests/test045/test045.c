#include <msxlib/msxbios.h>
#include <msxlib/bcdf.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int test001();
int test002();
int test003();
int test004();
int test005();
int test006();

int main() 
{
    dos_scode(1);
    test001();
    test002();
    test003();
    test004();
    test005();
    test006();
    dos_scode(0);

    return 0;
}

int test001() {
    char *a = "0.123e+5";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x45, 0x12, 0x30, 0, 0, 0, 0, 0,
    };

    printf("test045-001:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 8);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test002() {
    char *a = "123.456e-20";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x2f, 0x12, 0x34, 0x56, 0, 0, 0, 0,
    };

    printf("test045-002:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 11);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test003() {
    char *a = "54234.34e23";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x5c, 0x54, 0x23, 0x43, 0x40, 0, 0, 0,
    };

    printf("test045-003:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 11);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test004() {
    char *a = "2222.34e66";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test045-004:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}

int test005() {
    char *a = "2222.e23";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x5b, 0x22, 0x22, 0x00, 0x00, 0, 0, 0,
    };

    printf("test045-005:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 8);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test006() {
    char *a = "234.23e";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x43, 0x23, 0x42, 0x30, 0x00, 0, 0, 0,
    };

    printf("test045-006:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 6);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}
