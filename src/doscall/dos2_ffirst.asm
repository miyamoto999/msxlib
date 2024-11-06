    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_ffirst
    PUBLIC _dos2_ffirst
    PUBLIC ___dos2_ffirst


; /* 最初のエントリの検索 */
; uint8_t __LIB__ dos2_ffirst(void *fib, char *filename, uint8_t attr, MSX_FIB *new_fib) __smallc;
;
; sp + 2        new_fib
; sp + 4        attr
; sp + 6        filename
; sp + 8        fib
;
dos2_ffirst:
_dos2_ffirst:
___dos2_ffirst:
    
    ld hl,6
    add hl,sp

    ; filenameを取り出す
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl
    ; fibを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)

    ; new_fibを取り出す
    ld hl,2
    add hl,sp
    push ix
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    push hl
    pop ix

    ; attrを取り出す
    ld hl,4+2
    add hl,sp
    ld a,(hl)

    ld h,b
    ld l,c
    ld b,a

    ld c,_FFIRST
    call BDOS
    pop ix

    ld l,a
    ret