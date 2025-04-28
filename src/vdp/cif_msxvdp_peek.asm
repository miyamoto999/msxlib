    SECTION code_user
    PUBLIC msxvdp_peek
    PUBLIC _msxvdp_peek
    PUBLIC ___msxvdp_peek

    EXTERN asm_msxvdp_peek
    EXTERN _g_msxvdp_port_m,_g_msxvdp_write_port_1,asm_msxvdp_set_vram_addr,_g_msxvdp_vram_addr_msb, _g_msxvdp_vram_write_flag


; VRAMからデータを読み込む(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; uint8_t __LIB__ msxvdp_peek(uint32_t addr) __smallc
; {
;     uint8_t a[3];
;     a[0] = (addr >> 14) & 0x07;
;     a[1] = addr & 0xff;
;     a[2] = ((addr >> 8) & 0x3f);

;     z80_di();
;     msxvdp_set_reg_ndi(14, a[0]);
;     outp(MSXVDP_WRITE_PORT_1, a[1]);
;     outp(MSXVDP_WRITE_PORT_1, a[2]);
;     z80_ei();
    
;     return msxvdp_peek_next();
; }
msxvdp_peek:
_msxvdp_peek:
___msxvdp_peek:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ld a,(hl)

    ld (_g_msxvdp_vram_addr_msb),a

    xor a
    ld (_g_msxvdp_vram_write_flag),a

    ex de,hl

    call asm_msxvdp_peek

    ld l,a
    ret

