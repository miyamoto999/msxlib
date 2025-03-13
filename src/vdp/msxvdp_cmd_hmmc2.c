#include <msxlib/vdp.h>

/* HMMCコマンドの実行 */
void __LIB__ msxvdp_hmmc(MSXVDP_REG_DATA_HMMC *reg_data, char *datas, uint16_t size) __smallc
{
    uint16_t idx = 0;
    uint8_t status;

    reg_data->first_data = (uint8_t)datas[idx];
    idx++;

    msxvdp_set_reg_indirect(36);
    for(int i = 0; i < sizeof(MSXVDP_REG_DATA_HMMC); i++)
    {
        msxvdp_set_reg_indirect_val(((uint8_t *)reg_data)[i]);
    }
    msxvdp_set_reg_indirect_val(MSXVDP_CMD_HMMC);

    while(TRUE) {
        status = msxvdp_get_status(2);
        if((status & MSXVDP_STATUS2_CE) == 0) {
            return;
        }
        if((status & MSXVDP_STATUS2_TR) != 0) {
            if(idx < size) {
                msxvdp_set_reg(44, datas[idx]);
                idx++;
            } else {
                msxvdp_set_reg(44, 0);
            }
        }
    }
}