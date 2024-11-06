    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_fnext
    PUBLIC _dos2_fnext
    PUBLIC ___dos2_fnext


; /* 次のエントリの検索 */
; uint8_t __LIB__ dos2_fnext(MSX_FIB *fib) __smallc;

dos2_fnext:
_dos2_fnext:
___dos2_fnext:
    ld hl,2
    add hl,sp
    
    push ix
    ld e,(hl)
    inc hl
    ld d,(hl)

    push de
    pop ix

    ld c,_FNEXT
    call BDOS
    pop ix

    ld l,a
    ret