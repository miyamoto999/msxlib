    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_gtime
    PUBLIC _dos1_gtime
    PUBLIC ___dos1_gtime

; /* 時間の取得 */
; void __LIB__ dos1_gtime(uint8_t *hour, uint8_t *min, uint8_t *sec);
;
;   sp + 2  *sec
;   sp + 4  *min
;   sp + 6  *hour
dos1_gtime:
_dos1_gtime:
___dos1_gtime:
    ld c,_GTIME
    call BDOS

    ld b,h
    ld c,l
    ld a,d

    ld hl,2
    add hl,sp

    ; sec
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld (de),a

    ; min
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ex hl,de
    ld (hl),c
    ex hl,de

    ld e,(hl)
    inc hl
    ld d,(hl)

    ex hl,de
    ld (hl),b

    ret
