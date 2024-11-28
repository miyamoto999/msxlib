#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

long heap;

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 
    
    uint8_t sec;
    uint16_t sec_size, cluster, unused_cluster;
    uint8_t *dpb_pointer, *fat_pointer;

    dos_scode(1);

    dos1_alloc(0, &sec, &sec_size, &cluster, &unused_cluster, &dpb_pointer, &fat_pointer);
 
    printf("sec = %d\n", sec);
    printf("sec_size = %u\n", sec_size);
    printf("cluster = %u\n", cluster);
    printf("unused_cluser = %u\n", unused_cluster);
    printf("dpb_pointer = %x\n", dpb_pointer);
    printf("fat_pointer = %x\n", fat_pointer);

    printf("DPB:\n");
    for(int i = 0; i < 21; i+=8) {
        printf("%04x:", i & 0xffff);
        for(int j = 0; j < 8; j++) {
            if(i + j >= 21) {
                break;
            }
            printf("%02x ", dpb_pointer[i + j] & 0xff);
        }
        printf("\n");
    }

    dos_scode(0);

    return 0;
}