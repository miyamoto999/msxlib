
    SECTION code_user
    PUBLIC msxvdp_poke
    PUBLIC _msxvdp_poke
    PUBLIC ___msxvdp_poke

    EXTERN asm_msxvdp_poke

    EXTERN _g_msxvdp_port_n,_g_msxvdp_write_port_1,_g_msxvdp_vram_addr_msb, _g_msxvdp_vram_write_flag, asm_msxvdp_set_vram_addr

; VRAMにデータを書き込む(C言語インターフェイス)
;
; ↓これと同等の処理を行っている。
; void __LIB__ msxvdp_poke(uint32_t addr, uint8_t data) __smallc
; {
;     uint8_t a[3];
;     a[0] = (addr >> 14) & 0x07;
;     a[1] = addr & 0xff;
;     a[2] = ((addr >> 8) & 0x3f) | 0x40;

;     z80_di();
;     msxvdp_set_reg_ndi(14, a[0]);
;     outp(MSXVDP_WRITE_PORT_1, a[1]);
;     outp(MSXVDP_WRITE_PORT_1, a[2]);
;     z80_ei();

;     msxvdp_poke_next(data);
; }
msxvdp_poke:
_msxvdp_poke:
___msxvdp_poke:
    ld hl,2
    add hl,sp

    ld b,(hl)
    inc hl
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ld a,(hl)

    ld (_g_msxvdp_vram_addr_msb),a

    ex de,hl

    ld a,1
    ld (_g_msxvdp_vram_write_flag),a

    ld a,b

    jp asm_msxvdp_poke

