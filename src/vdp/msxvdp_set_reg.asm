    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"
    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC msxvdp_set_reg
    PUBLIC _msxvdp_set_reg
    PUBLIC ___msxvdp_set_reg

    PUBLIC msxvdp_set_reg_ndi
    PUBLIC _msxvdp_set_reg_ndi
    PUBLIC ___msxvdp_set_reg_ndi

    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_write_port_2, _g_msxvdp_reg_saves


; void vdp_set_reg(uint8_t reg, uint8_t val);
;
;   SP+2 val
;   SP+4 reg

msxvdp_set_reg:
_msxvdp_set_reg:
___msxvdp_set_reg:
    ; val を取り出す。
    ld hl,2
    add hl,sp
    ld d,(hl)   ; valをdにバックアップ

    ; regを取り出す。
    ld hl,4
    add hl,sp
    ld b,(hl)   ; regをbにバックアップ

    ; IOポートを取得
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    di
    ; VDPレジスタに値を設定
    MAC_VDP_SET_REG b,d
    ei
    
FUNC_EXIT:
    ; 28以上のレジスタは保存しない
    ld a,b
    cp 27
    jp P,L_SKIP

    ; 値保存用のアドレスを計算する。
    sla b
    ld c,b
    ld b,0
    ld hl,_g_msxvdp_reg_saves
    add hl,bc

    ld c,(hl)
    inc hl
    ld b,(hl)

    ld a,d
    ld (bc),a

L_SKIP:

    ret


; void vdp_set_reg_ndi(uint8_t reg, uint8_t val);
;
;   SP+2 val
;   SP+4 reg

msxvdp_set_reg_ndi:
_msxvdp_set_reg_ndi:
___msxvdp_set_reg_ndi:
    ; val を取り出す。
    ld hl,2
    add hl,sp
    ld d,(hl)   ; valをdにバックアップ

    ; regを取り出す。
    ld hl,4
    add hl,sp
    ld b,(hl)   ; regをbにバックアップ

    ; IOポートを取得
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    ; VDPレジスタに値を設定
    MAC_VDP_SET_REG b,d

    jp FUNC_EXIT

