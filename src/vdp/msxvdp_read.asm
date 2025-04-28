    SECTION code_user
    PUBLIC asm_msxvdp_read, asm_msxvdp_read_next
    EXTERN _g_msxvdp_vram_write_flag,_g_msxvdp_port_n,asm_msxvdp_set_vram_addr

; VRAMに複数データを読み込む
;
; 入力
;    _g_msxvdp_vram_addr_msb <- VRAMのアドレス(最上位ビット)
;    hl <- VRAMのアドレス
;    de <- 読み込むデータの保存アドレス
;    bc <- 読み込むデータの数
; 破壊レジスタ
;   a,f,c,d,e,h,l
asm_msxvdp_read:
    xor a
    ld (_g_msxvdp_vram_write_flag),a
    push de
    push bc
    call asm_msxvdp_set_vram_addr
    pop bc
    pop hl
    jp asm_msxvdp_read_next


; VRAMに複数データを読み込む(つづき)
;
; 入力
;    hl <- 読み込むデータの保存アドレス
;    bc <- 読み込むデータの数
; 破壊レジスタ
;    a,f,c,d,e,h,l
asm_msxvdp_read_next:
    ld d,b
    ld e,c
    ld a,(_g_msxvdp_port_n)
    ld c,a
LOOP:
    in a,(c)
    ld (hl),a
    inc hl
    dec de
    ld a,e
    or d
    jr nz,LOOP

    ret