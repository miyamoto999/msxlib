    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_wrzer
    PUBLIC _dos1_wrzer
    PUBLIC ___dos1_wrzer

; /* ゼロフィルを行うランダム書き込み(FCB) */
; uint8_t __LIB__ dos1_wrzer(MSX_FCB *fcb) __smallc;
dos1_wrzer:
_dos1_wrzer:
___dos1_wrzer:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_WRZER
    jp BDOS
