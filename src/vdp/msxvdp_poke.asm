    SECTION code_user
    PUBLIC asm_msxvdp_poke

    EXTERN asm_msxvdp_set_vram_addr,_g_msxvdp_port_n

; VRAMにデータを書き込む
;
; 入力
;    _g_msxvdp_vram_addr_msb <- VRAMのアドレス(最上位ビット)
;    hl <- VRAMのアドレス(下位16ビット)
;    a <- 書き込むデータ
; 破壊レジスタ
;    a,f,b,c,d,h,l
asm_msxvdp_poke:
    ld d,a

    call asm_msxvdp_set_vram_addr

    ld a,(_g_msxvdp_port_n)
    ld c,a
    ld a,d
    out (c),a

    ret

