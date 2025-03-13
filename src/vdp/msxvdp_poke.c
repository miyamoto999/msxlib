#include <msxlib/vdp.h>

/* VRAMにデータを書き込む */
void __LIB__ msxvdp_poke(uint32_t addr, uint8_t data) __smallc
{
    uint8_t a[3];
    a[0] = (addr >> 14) & 0x07;
    a[1] = addr & 0xff;
    a[2] = ((addr >> 8) & 0x3f) | 0x40;

    z80_di();
    msxvdp_set_reg_ndi(14, a[0]);
    outp(MSXVDP_WRITE_PORT_1, a[1]);
    outp(MSXVDP_WRITE_PORT_1, a[2]);
    z80_ei();

    msxvdp_poke_next(data);
}