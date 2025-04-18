; /*********************************************************
;  dsk1_gdate.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_gdate.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_gdate
    PUBLIC _dsk1_gdate
    PUBLIC ___dsk1_gdate

; /* 日付の取得 */
; void __LIB__ dsk1_gdate(uint16_t *year, uint8_t *month, uint8_t *mday, uint8_t *wday);
;
;   sp + 2  *wday
;   sp + 4  *mday
;   sp + 6  *month
;   sp + 8  *year
;
dsk1_gdate:
_dsk1_gdate:
___dsk1_gdate:
    ld c,_GDATE
    call BDOS_DSK

    push hl

    ld hl,4
    add hl,sp

    ; wday
    ld b,d
    ld c,e

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ex hl,de
    ld (hl),a

    ex hl,de
    ; mday
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ex hl,de

    ld (hl),c

    ex hl,de

    ; month
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ex hl,de
    ld (hl),b
    ex hl,de

    pop bc
    
    ; year
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ex hl,de

    ld (hl),c
    inc hl
    ld (hl),b

    ret
