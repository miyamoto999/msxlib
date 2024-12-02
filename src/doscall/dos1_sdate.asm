    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_sdate
    PUBLIC _dos1_sdate
    PUBLIC ___dos1_sdate


; /* 日付の設定 */
; uint8_t __LIB__ dos1_sdate(uint16_t year, uint8_t month, uint8_t mday);
dos1_sdate:
_dos1_sdate:
___dos1_sdate:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    inc hl

    ld d,(hl)
    inc hl
    inc hl

    ld c,(hl)
    inc hl
    ld b,(hl)

    ld h,b
    ld l,c

    ld c, _SDATE
    call BDOS

    ld l,a
    ret
