    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_wrseq
    PUBLIC _dos1_wrseq
    PUBLIC ___dos1_wrseq

; /* シーケンシャルな書き込み(FCB) */
; uint8_t __LIB__ dos1_wrseq(MSX_FCB *fcb) __smallc;
dos1_wrseq:
_dos1_wrseq:
___dos1_wrseq:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_WRSEQ
    jp BDOS