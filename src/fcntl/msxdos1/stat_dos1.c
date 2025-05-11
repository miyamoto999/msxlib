#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcntl.h>
#include <msxlib/time.h>
#include <string.h>
#include <time.h>

int __LIB__ stat_dos1(char *filename, struct stat *buf) __smallc
{
    MSX_FCB fcb;
    time_t t = 0;
    struct tm tm;

    if (filename == NULL || buf == NULL) {
        return -1;
    }

    memset(buf, 0, sizeof(struct stat));
    memset(&tm, 0, sizeof(struct tm));

    msx_fcb_init(&fcb, filename);
    int8_t ret = dos1_fopen(&fcb);
    if (ret != 0) {
        return -1;
    }

    buf->st_mode = S_IFREG | S_IRUSR | S_IWUSR | S_IXUSR \
                | S_IRGRP | S_IWGRP | S_IXGRP \
                | S_IROTH | S_IWOTH | S_IXOTH;
    if(dos_getkerver() < 2) {
        t = dostime2time(fcb.v1.date, fcb.v1.time);
        if(t == -1) {
            t = 0;
        }
    }
    buf->st_size = fcb.v1.file_size;
    
    buf->st_blksize = 512;
    buf->st_blocks = buf->st_size / buf->st_blksize;

    buf->st_dev = 1;
    buf->st_nlink = 0;

    dos1_fclose(&fcb);

    if(dos_getkerver() >= 2) {
        uint16_t dos_date, dos_time;
        ret = dos2_ftime(filename, 0, &dos_time, &dos_date);
        if(ret == 0) {
            t = dostime2time(dos_date, dos_time);
            if(t == -1) {
                t = 0;
            }
        } else {
            t = 0;
        }
    }

    buf->st_atime = t;
    buf->st_mtime = t;
    buf->st_ctime = t;

    return 0;
}