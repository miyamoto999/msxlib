    SECTION code_user

    PUBLIC msxvdp_read
    PUBLIC _msxvdp_read
    PUBLIC ___msxvdp_read

    PUBLIC msxvdp_read_next
    PUBLIC _msxvdp_read_next
    PUBLIC ___msxvdp_read_next

    EXTERN asm_msxvdp_read, asm_msxvdp_read_next
    EXTERN _g_msxvdp_vram_addr_msb, _g_msxvdp_vram_write_flag, _g_msxvdp_port_n, asm_msxvdp_set_vram_addr

; VRAMからブロックデータを読み込む(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; void __LIB__ msxvdp_read(uint32_t addr, uint8_t *data, uint16_t size) __smallc
; {
;     uint16_t idx = 0;

;     data[idx] = msxvdp_peek(addr);
;     idx++;
;     for(; idx < size; idx++) {
;         data[idx] = msxvdp_peek_next();
;     }
; }
msxvdp_read:
_msxvdp_read:
___msxvdp_read:
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

    jp asm_msxvdp_read

; VRAMから複数データを読み込む(つづき)(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; void __LIB__ msxvdp_read_next(uint8_t *data, uint16_t size) __smallc
; {
;     for(uint16_t i = 0; i < size; i++) {
;         data[i] = msxvdp_peek_next();
;     }
; }
msxvdp_read_next:
_msxvdp_read_next:
___msxvdp_read_next:
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

    jp asm_msxvdp_read_next


