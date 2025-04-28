    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_gdate
    PUBLIC _dos1_gdate
    PUBLIC ___dos1_gdate
    EXTERN msxlib_doscall

; /* 日付の取得 */
; void __LIB__ dos1_gdate(uint16_t *year, uint8_t *month, uint8_t *mday, uint8_t *wday);
;
;   sp + 2  *wday
;   sp + 4  *mday
;   sp + 6  *month
;   sp + 8  *year
;
dos1_gdate:
_dos1_gdate:
___dos1_gdate:
    ld c,_GDATE
    call msxlib_doscall

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
