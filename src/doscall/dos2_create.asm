
    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_create
    PUBLIC _dos2_create
    PUBLIC ___dos2_create
    EXTERN msxlib_doscall


; /* ファイルハンドルの作成 */
; uint8_t dos2_create(const char *filepath, uint8_t mode, uint8_t attr, uint8_t *handle);
; sp + 2    handle
; sp + 4    attr
; sp + 6    mode
; sp + 8    filepath
dos2_create:
_dos2_create:
___dos2_create:
    ld hl,4
    add hl,sp

    ld b,(hl)
    inc hl
    inc hl

    ld a,(hl)
    inc hl
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_CREATE
    call msxlib_doscall

    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ex hl,de

    ld (hl),b

    ld l,a

    ret