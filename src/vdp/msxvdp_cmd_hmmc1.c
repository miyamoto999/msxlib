#include <msxlib/vdp.h>

/* HMMCのコマンド送信 */
void __LIB__ msxvdp_hmmc_start(MSXVDP_REG_DATA_HMMC *reg_data) __smallc
{
    msxvdp_set_reg_indirect(36);
    for(int i = 0; i < sizeof(MSXVDP_REG_DATA_HMMC); i++)
    {
        msxvdp_set_reg_indirect_val(((uint8_t *)reg_data)[i]);
    }
    msxvdp_set_reg_indirect_val(MSXVDP_CMD_HMMC);
}

/* HMMCの次のデータを送信 */
BOOL __LIB__ msxvdp_hmmc_next(uint8_t data) __smallc
{
    uint8_t status;

    while(TRUE) {
        status = msxvdp_get_status(2);
        if((status & MSXVDP_STATUS2_CE) == 0) {
            return TRUE;
        }
        if((status & MSXVDP_STATUS2_TR) != 0) {
            break;
        }
    }
    msxvdp_set_reg(44, data);
    
    return FALSE;
}
