#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>
#include <msxlib/msxwork.h>

/*
long heap;
*/
#define TEST_FILE   "test.bin"
#define RECORD_SIZE 128
char buf[RECORD_SIZE], buf2[RECORD_SIZE];

static void test1(void);

int main()
{
/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
*/
    char *tmp = malloc(128);
    printf("tmp = %x\n", tmp);
    for(int i = 0; i < 128; i++) {
        tmp[i] = (char)i;
    }    

    printf("HIMEM = %x\n", MSXWORK_HIMEM_VAL);
    printf("MSXWORK_MEMSIZ = %x\n", MSXWORK_MEMSIZ_VAL);
    printf("MSXWORK_STKTOP = %x\n", MSXWORK_STKTOP_VAL);
    printf("sp = %x\n", msx_get_reg_sp());

    dos_scode(1);

    test1();

    int counter = 0;
    for(int i = 0; i < 128; i++) {
        if(tmp[i] != (char)i && counter < 10) {
            printf("Error: i = %d, tmp[i] = %d, 0x%x\n", i, tmp[i], tmp[i]);
            counter++;
        }
    }

    printf("tmp = %x\n", tmp);
    printf("HIMEM = %x\n", MSXWORK_HIMEM_VAL);
    printf("MSXWORK_MEMSIZ = %x\n", MSXWORK_MEMSIZ_VAL);
    printf("MSXWORK_STKTOP = %x\n", MSXWORK_STKTOP_VAL);
    printf("sp = %x\n", msx_get_reg_sp());
    dos_scode(0);

    MSX_FCB fcb;
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    return 0;
}

static void test1(void)
{
    uint8_t ret;
    MSX_FCB fcb;
    BFILE *bfp;
    uint16_t size;

    printf("dos1_wrzer() test1:");

    for(int i = 0; i < RECORD_SIZE; i++) {
        buf[i] = (char)i;
    }

    /* ファイルを作る */
    msx_fcb_init(&fcb, TEST_FILE);

    ret = dos1_fmake(&fcb);
    assert(ret == 0);
    dos1_setdta(buf);
    cpm_fcb_set_random_record(&fcb, 0);
    ret = dos1_wrzer(&fcb);
    assert(ret == 0);
    cpm_fcb_set_random_record(&fcb, 3);
    ret = dos1_wrzer(&fcb);
    assert(ret == 0);
    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    /* チェック */
    bfp = bfile_open(TEST_FILE, BFILE_O_RDONLY, 128);
    assert(bfp);
    bfile_fseek(bfp, 0, BFILE_SEEK_SET);
    size = bfile_read(bfp, buf2, RECORD_SIZE);
    assert(size == RECORD_SIZE);
    assert(memcmp(buf, buf2, RECORD_SIZE) == 0);

    size = bfile_read(bfp, buf2, RECORD_SIZE);
    memset(buf, 0, RECORD_SIZE);
    assert(size == RECORD_SIZE);
    assert(memcmp(buf, buf2, RECORD_SIZE) == 0);

    size = bfile_read(bfp, buf2, RECORD_SIZE);
    assert(size == RECORD_SIZE);
    assert(memcmp(buf, buf2, RECORD_SIZE) == 0);

    size = bfile_read(bfp, buf2, RECORD_SIZE);
    for(int i = 0; i < RECORD_SIZE; i++) {
        buf[i] = (char)i;
    }
    assert(size == RECORD_SIZE);
    assert(memcmp(buf, buf2, RECORD_SIZE) == 0);

    size = bfile_read(bfp, buf2, RECORD_SIZE);
    assert(size == 0);
    assert(bfile_eof(bfp));

    bfile_close(bfp);

    printf("OK\n");
}
