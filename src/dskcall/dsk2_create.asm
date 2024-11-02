; /*********************************************************
;  dsk2_create.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk2_create.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/


    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk2_create
    PUBLIC _dsk2_create
    PUBLIC ___dsk2_create


; /* ファイルハンドルの作成 */
; uint8_t dsk2_create(const char *filepath, uint8_t mode, uint8_t attr, uint8_t *handle);
; sp + 2    handle
; sp + 4    attr
; sp + 6    mode
; sp + 8    filepath
dsk2_create:
_dsk2_create:
___dsk2_create:
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
    call BDOS_DSK

    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ex hl,de

    ld (hl),b

    ld l,a

    ret