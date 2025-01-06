#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>
#include <msxlib/iot.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <float.h>

#define BUF_SIZE 256
static char buf[BUF_SIZE];

int main() 
{
    char bcdf[BCDF_DOUBLE_SIZE];
    BOOL ret;

    dos_scode(1);

    ret = iot_getbcdf("device/dht/humidity", bcdf);
    assert(ret);
    bcdf2str(bcdf, BCDF_DOUBLE_SIZE, buf, BUF_SIZE);
    printf("Humidity: %s\n", buf);

    ret = iot_getbcdf("device/dht/temperature", bcdf);
    assert(ret);
    bcdf2str(bcdf, BCDF_DOUBLE_SIZE, buf, BUF_SIZE);
    printf("Temperature: %s\n", buf);

    ret = iot_getbcdf("device/accel/y", bcdf);
    assert(!ret);

    ret = iot_getbcdf("device/dht/temperature", bcdf);
    assert(ret);

    ret = iot_getbcdf("host/sw_version", bcdf);
    assert(!ret);

    ret = iot_getbcdf("device/dht/temperature", bcdf);
    assert(ret);

    dos_scode(0);

    return 0;
}

