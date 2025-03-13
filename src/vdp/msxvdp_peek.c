#include <msxlib/vdp.h>

/**
 * @brief VRAMからデータを読み込む
 * 
 * @param addr VRAMアドレス
 * @return uint8_t データ
 */
uint8_t __LIB__ msxvdp_peek(uint32_t addr) __smallc
{
    uint8_t a[3];
    a[0] = (addr >> 14) & 0x07;
    a[1] = addr & 0xff;
    a[2] = ((addr >> 8) & 0x3f);

    z80_di();
    msxvdp_set_reg(14, a[0]);
    outp(MSXVDP_WRITE_PORT_1, a[1]);
    outp(MSXVDP_WRITE_PORT_1, a[2]);
    z80_ei();
    
    return msxvdp_peek_next();
}