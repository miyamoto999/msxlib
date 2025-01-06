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
int test007();
int test008();
int test009();

int main() 
{
    dos_scode(1);
    test001();
    test002();
    test003();
    test004();
    test005();
    test006();
    test007();
    test008();
    test009();
    dos_scode(0);

    return 0;
}

int test001() {
    char *a = "0.123";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x40, 0x12, 0x30, 0, 0, 0, 0, 0,
    };

    printf("test043-001:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 5);

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
    char *a = ".1234";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x40, 0x12, 0x34, 0, 0, 0, 0, 0,
    };

    printf("test043-002:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 5);

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
    char *a = "123.456";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x43, 0x12, 0x34, 0x56, 0, 0, 0, 0,
    };

    printf("test043-003:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 7);

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
    char *a = "0.000123";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x3d, 0x12, 0x30, 0x00, 0, 0, 0, 0,
    };

    printf("test043-004:test str2bcdf(\"%s\"):", a);
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

int test005() {
    char *a = "0.99999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x40, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };

    printf("test043-005:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 16);

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
    char *a = "0.999999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    printf("test043-006:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 17);

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

int test007() {
    char *a = "0.0000099999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x3b, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };

    printf("test043-007:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 21);

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

int test008() {
    char *a = "0.000000000000000000000000000000000000000000000000000000000000000099999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x00, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };

    printf("test043-008:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 80);

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

int test009() {
    char *a = "0.00000000000000000000000000000000000000000000000000000000000000000099999999999999";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test043-009:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}
