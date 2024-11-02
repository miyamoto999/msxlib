
    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_open
    PUBLIC _dos2_open
    PUBLIC ___dos2_open


; /* ファイルハンドルのオープン */
; uint8_t __LIB__ dos2_open(const char *filepath, uint8_t mode, uint8_t *handle) __smallc;
; sp + 2    handle
; sp + 4    mode
; sp + 6    filepath
dos2_open:
_dos2_open:
___dos2_open:
    ld hl,4
    add hl,sp

    ; modeとりだし
    ld a,(hl)
    inc hl
    inc hl

    ; filepathの取り出し
    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_OPEN
    call BDOS

    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ex hl,de

    ld (hl),b

    ld l,a

    ret