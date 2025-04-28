    SECTION code_user
    PUBLIC asm_msxvdp_peek

    EXTERN _g_msxvdp_port_m, asm_msxvdp_set_vram_addr

; VRAMにデータを読み込む
;
; 入力
;    ehl <- VRAMのアドレス
; 出力
;    a <- 読み込んだデータ
; 破壊レジスタ
;    a,f,b,c,e,h,l
asm_msxvdp_peek:
    call asm_msxvdp_set_vram_addr

    ld a,(_g_msxvdp_port_m)
    ld c,a
    in a,(c)

    ret
