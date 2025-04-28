    include "msxlib/asm/vdp.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC asm_msxvdp_set_vram_addr
    EXTERN _g_msxvdp_write_port_1, _g_msxvdp_vram_addr_msb, _g_msxvdp_vram_write_flag
    
; 読み書きするVRAMのアドレスを設定する
; ※ 割り込み禁止、解除をおこなっている
; 入力
;    _g_msxvdp_vram_addr_msb <- VRAMのアドレス(上位ビット)
;    _g_msxvdp_vram_write_flag <- 書き込みフラグ
;    hl <- VRAMのアドレス
; 破壊レジスタ
;    a,f,b,c,h,l
asm_msxvdp_set_vram_addr:
    ; IOポートを取得
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    ; VRAMアドレスを設定
    push hl

    ld a,(_g_msxvdp_vram_addr_msb)
    ; ahを6ビット右シフト
    srl a
    rr h
    srl a
    rr h
    srl a
    rr h
    srl a
    rr h
    srl a
    rr h
    srl a
    rr h
    ld a,7
    and h
    ld b,a
    di
    MAC_VDP_SET_REG 14,a

    pop hl
    
    ld a,b
    ld (MSXWORK_RG14SAV),a
    
    ld a,l
    out (c),a

    ld a,(_g_msxvdp_vram_write_flag)
    ld l,0
    or a
    jr z,READ_MODE
    ld l,0x40
READ_MODE:
    ld a,0x3f
    and h
    or l
    out (c),a
    ei
    ret