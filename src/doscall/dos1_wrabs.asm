    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_wrabs
    PUBLIC _dos1_wrabs
    PUBLIC ___dos1_wrabs

; /* アブソリュートなセクタ書き込み */
; uint8_t __LIB__ dos1_wrabs(uint8_t drv, uint16_t sec, uint8_t num);
;
;   sp + 2  num
;   sp + 4  sec
;   sp + 6  drv
dos1_wrabs:
_dos1_wrabs:
___dos1_wrabs:
    ld hl,2
    add hl,sp

    ld a,(hl)
    inc hl
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld l,(hl)
    
    ld h,a

    ld c,_WRABS
    call BDOS
    ld l,a
    ret
