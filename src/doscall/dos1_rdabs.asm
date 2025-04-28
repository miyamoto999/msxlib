    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_rdabs
    PUBLIC _dos1_rdabs
    PUBLIC ___dos1_rdabs
    EXTERN msxlib_doscall

; /* アブソリュートなセクタ読み込み */
; uint8_t __LIB__ dos1_rdabs(uint8_t drv, uint16_t sec, uint8_t num);
;
;   sp + 2  num
;   sp + 4  sec
;   sp + 6  drv
dos1_rdabs:
_dos1_rdabs:
___dos1_rdabs:
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

    ld c,_RDABS
    call msxlib_doscall
    ld l,a
    ret
