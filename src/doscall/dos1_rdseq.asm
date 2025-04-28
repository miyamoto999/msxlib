    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_rdseq
    PUBLIC _dos1_rdseq
    PUBLIC ___dos1_rdseq
    EXTERN msxlib_doscall


; /* シーケンシャル読み込み(FCB) */
; uint8_t __LIB__ dos1_rdseq(void *fcb) __smallc;

dos1_rdseq:
_dos1_rdseq:
___dos1_rdseq:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_RDSEQ
    jp msxlib_doscall
