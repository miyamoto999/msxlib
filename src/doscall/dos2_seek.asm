    include "msxlib/asm/msxdos.inc"

    SECTION code_user
    PUBLIC dos2_seek
    PUBLIC _dos2_seek
    PUBLIC ___dos2_seek
    EXTERN msxlib_doscall


; /* ファイルハンドルポインタの移動 */
; uint8_t __LIB__ dos2_seek(uint8_t handle, int32_t *pos, uint8_t whence) __smallc;
; sp + 2    whence
; sp + 4    *pos
; sp + 6    handle
dos2_seek:
_dos2_seek:
___dos2_seek:
    ld hl,4
    add hl,sp

    ; pos 取り出し
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    push de
    ld e,(hl)
    inc hl
    ld d,(hl)

    ; handleの取り出し
    ld hl, 6 + 2
    add hl,sp
    ld b,(hl)

    ; whenceの取り出し
    ld hl,2 + 2
    add hl,sp
    ld a,(hl)

    pop hl

    ld c,_SEEK
    call msxlib_doscall

    ; posにセット
    ld b,h
    ld c,l

    ld hl,4
    add hl,sp

    push af
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ld (hl),c
    inc hl
    ld (hl),b
    inc hl
    ld (hl),e
    inc hl
    ld (hl),d

    pop af

    ld l,a

    ret



