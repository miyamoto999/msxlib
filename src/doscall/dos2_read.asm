
    include "msxlib/asm/msxdos.inc"

    SECTION code_user
    PUBLIC dos2_read
    PUBLIC _dos2_read
    PUBLIC ___dos2_read

; /* ファイルハンドルからの読み出し */
; uint8_t __LIB__ dos2_read(uint8_t handle, void *buf, uint16_t count, uint16_t *bytes) __smallc;
; sp + 2    bytes
; sp + 4    count
; sp + 6    buf
; sp + 8    handle
dos2_read:
_dos2_read:
___dos2_read:
    ld hl,4
    add hl,sp

    ; count取り出し
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; bufの取り出し
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ; handleの取り出し
    ld a,(hl)

    ld h,b
    ld l,c
    ld b,a

    ex hl,de

    ld c,_READ
    call BDOS

    ex hl,de

    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld b,(hl)

    ld l,c
    ld h,b

    ld (hl),e
    inc hl
    ld (hl),d

    ld l,a

    ret
