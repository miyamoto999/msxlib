#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

long heap;

#define TEST_FILE   "test.bin"
#define RECORD_SIZE 128

static void test1(void);
void fcb_set(MSX_FCB *fcb, uint16_t ext_num, uint8_t cur_rec);

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
    
    dos_scode(1);

    test1();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t ret;
    MSX_FCB fcb;
    uint16_t ext_num = 0x200;
    uint8_t cur_rec = 23;

    printf("dos1_setrnd() test1:");

    msx_fcb_init(&fcb, TEST_FILE);

    fcb_set(&fcb, ext_num, cur_rec);
    dos1_setrnd(&fcb);
    assert(cpm_fcb_get_random_record(&fcb) == (long)ext_num * RECORD_SIZE + cur_rec);

    ext_num = 0xffff;
    cur_rec = 127;
    fcb_set(&fcb, ext_num, cur_rec);
    dos1_setrnd(&fcb);
    assert(cpm_fcb_get_random_record(&fcb) == (long)ext_num * RECORD_SIZE + cur_rec);

    printf("OK\n");
}

void fcb_set(MSX_FCB *fcb, uint16_t ext_num, uint8_t cur_rec)
{
    fcb->cpm.ext_num_low = ext_num & 0xff;
    fcb->cpm.ext_num_high = ext_num >> 8;
    fcb->cpm.cur_record = cur_rec;
}
