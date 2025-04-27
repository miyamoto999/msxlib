    SECTION code_user
    PUBLIC asm_msxvdp_write
    PUBLIC asm_msxvdp_write_next

    EXTERN _g_msxvdp_vram_write_flag, asm_msxvdp_set_vram_addr, _g_msxvdp_port_n

; VRAMに複数データを書き込む
;
; 入力
;    _g_msxvdp_vram_addr_msb <- VRAMのアドレス(上位ビット)
;    hl <- VRAMのアドレス
;    de <- 書き込むデータのアドレス
;    bc <- 書き込むデータの数
; 破壊レジスタ
;   a,f,c,d,e,h,l
asm_msxvdp_write:
    ld a,1
    ld (_g_msxvdp_vram_write_flag),a
    push de
    push bc
    call asm_msxvdp_set_vram_addr
    pop bc
    pop hl
    jp asm_msxvdp_write_next

; VRAMに複数データを書き込む(つづき)
;
; 入力
;    hl <- 書き込むデータのアドレス
;    bc <- 書き込むデータの数
; 破壊レジスタ
;    a,f,c,d,e,h,l
asm_msxvdp_write_next:
    ld d,b
    ld e,c
    ld a,(_g_msxvdp_port_n)
    ld c,a
LOOP:
    ld a,(hl)
    out (c),a
    inc hl
    dec de
    ld a,e
    or d
    jr nz,LOOP

    ret