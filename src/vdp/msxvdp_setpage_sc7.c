#include <msxlib/msxlib.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

/**
 * @brief SCREEN 7での表示ページを変更する。
 * 
 * @param page ページ番号(0〜1)
 */
void __LIB__ msxvdp_setpage_sc7(uint8_t page) __smallc
{
    uint8_t val = page << 5;
    val |= 0x1f;
    val &= 0x3f;
    msxvdp_set_reg(2, val);

    MSXWORK_DPPAGE_VAL = page;
    MSXWORK_ACPAGE_VAL = page;
}