#include <msxlib/vdp.h>

/* VDPのコマンドが終了するのを待つ*/
void __LIB__ msxvdp_cmd_wait(void) __smallc
{
    uint8_t status;

    while(TRUE) {
        status = msxvdp_get_status(2);
        if((status & MSXVDP_STATUS2_CE) == 0) {
            break;
        }
    }
}
