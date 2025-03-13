    include "msxlib/asm/msxwork.inc"
    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC msxvdp_set_reg_indirect, _msxvdp_set_reg_indirect, ___msxvdp_set_reg_indirect
    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_write_port_2, _g_msxvdp_reg_saves

; /* 間接指定のVDPレジスタ番号を設定する。　*/
; void __LIB__ msxvdp_set_reg_indirect(uint8_t reg) __smallc;
msxvdp_set_reg_indirect:
_msxvdp_set_reg_indirect:
___msxvdp_set_reg_indirect:
    ld hl,2
    add hl,sp

    ld d,(hl)
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    di
    MAC_VDP_SET_REG_INDIRECT d
    ei
    
    ld a,d
    ld (MSXWORK_RG17SAV),a

    ret