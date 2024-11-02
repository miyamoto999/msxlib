    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxvdp_set_reg
    PUBLIC _msxvdp_set_reg
    PUBLIC ___msxvdp_set_reg
    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_write_port_2, _g_vdp_reg_saves


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
    ld e,(hl)   ; regをeにバックアップ

    ; IOポートを取得
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    di

    ; valをIOポートに書き出す
    ld a,d      ; valをaに戻す
    out (c),a

    ; reg | 0x80を書き出す
    ld a,0x80
    or e
    out (c),a

    ; 28以上のレジスタは保存しない
    ld a,e
    cp 27
    jp P,L_SKIP

    ; 値保存用のアドレスを計算する。
    sla e
    ld c,e
    ld b,0
    ld hl,_g_vdp_reg_saves
    add hl,bc

    ld c,(hl)
    inc hl
    ld b,(hl)

    ld a,d
    ld (bc),a

L_SKIP:
    ei

    ret



