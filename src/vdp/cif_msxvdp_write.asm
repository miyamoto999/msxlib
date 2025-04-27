    SECTION code_user

    PUBLIC msxvdp_write
    PUBLIC _msxvdp_write
    PUBLIC ___msxvdp_write

    PUBLIC msxvdp_write_next
    PUBLIC _msxvdp_write_next
    PUBLIC ___msxvdp_write_next
    
    EXTERN asm_msxvdp_write, asm_msxvdp_write_next
    EXTERN _g_msxvdp_port_n, _g_msxvdp_vram_write_flag, _g_msxvdp_vram_addr_msb, asm_msxvdp_set_vram_addr
    
; VRAMにブロックデータを書き込む(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; void __LIB__ msxvdp_write(uint32_t addr, uint8_t *data, uint16_t size) __smallc
; {
;     uint16_t idx = 0;

;     msxvdp_poke(addr, data[idx]);
;     idx++;

;     for(; idx < size; idx++) {
;         msxvdp_poke_next(data[idx]);
;     }
; }
msxvdp_write:
_msxvdp_write:
___msxvdp_write:
    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    push de
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld a,(hl)
    ld (_g_msxvdp_vram_addr_msb),a

    pop hl

    ex de,hl

    jp asm_msxvdp_write


; VRAMにブロックデータを書き込む(つづき)(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; void __LIB__ msxvdp_write_next(uint8_t *data, uint16_t size) __smallc
; {
;     for(uint16_t i = 0; i < size; i++) {
;         msxvdp_poke_next(data[i]);
;     }
; }
msxvdp_write_next:
_msxvdp_write_next:
___msxvdp_write_next:
    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    jp asm_msxvdp_write_next

