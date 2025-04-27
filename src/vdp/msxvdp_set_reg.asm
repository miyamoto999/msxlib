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

    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_write_port_2


; void vdp_set_reg(uint8_t reg, uint8_t val);
; VDPレジスタとワークエリアに値を設定する
; ※ 内部で割り込み禁止、解除を行っている
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
    ; jp set_reg_workarea
    ; ret

; VDPレジスタ値のワークエリアに値を設定する
;
; 入力
;    b <- VDPレジスタ番号
;    d <- VDPレジスタの値
; 破壊レジスタ
;   a,f,b,c,e,h,l
set_reg_workarea:
    ld a,b
    ld b,0
    ; 8以上なら次
    cp 8
    jp P, NEXT1
    ld hl,MSXWORK_RG0SAV
    jr SET_WORKAREA
NEXT1:
    ; 24以上なら次
    cp 24
    jp P, NEXT2
    ld hl,MSXWORK_RG8SAV
    ld e,-8
    add a,e
    jr SET_WORKAREA
NEXT2:
    ; 28以上なら終了
    cp 28
    jp P, NOT_SET_RET
    ; 24でも終了
    cp 24
    jp z, NOT_SET_RET
    ld hl,MSXWORK_RG25SAV
    ld e,-25
    add a,e
SET_WORKAREA:
    ld c,a
    add hl,bc
    ld (hl),d

    xor a
    inc a
    ret

NOT_SET_RET:
    xor a
    ret


; void vdp_set_reg_ndi(uint8_t reg, uint8_t val);
; VDPレジスタとワークエリアに値を設定する。
; ※ 割り込み禁止を行わないバージョン
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

