#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcntl.h>
#include <msxlib/time.h>
#include <stdio.h>
#include <assert.h>

#define TEST_FILE "test.bin"

int main(void)
{
    int fd;
    struct tm tm;
    MSX_FCB fcb;
    uint8_t ret;

    dos_scode(1);

    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    close(fd);

    if(dos_getkerver() == 1) {
        msx_fcb_init(&fcb, TEST_FILE);
        ret = dos1_fopen(&fcb);
        assert(ret == 0);
        dostime2tm(fcb.v1.date, fcb.v1.time, &tm);
        printf("DOS1:File date: %04d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    } else if(dos_getkerver() == 2) {
        uint16_t file_date, file_time;
        ret = dos2_ftime(TEST_FILE, 0, &file_time, &file_date);
        assert(ret == 0);
        dostime2tm(file_date, file_time, &tm);
        printf("DOS2:File date: %04d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    }

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    dos_scode(0);

    return 0;
}