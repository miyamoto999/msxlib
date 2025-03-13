    include "msxlib/asm/msxdos.inc"

    SECTION code_clib
    PUBLIC  fputc_cons_native_dos2


;
; Entry:        hl = points to char
;
fputc_cons_native_dos2:
    ld      hl, 2
    add     hl, sp
    ld      a, (hl)

    push    ix                          ;save callers

    ex de,hl
    ld      c,_WRITE
    ld      b,1
    ld      hl,1
    cp      10
    jr      nz, nocrlf

    call BDOS
    ld      a, 13

    ld (de),a

    ld c,_WRITE
    ld b,1
    ld hl,1

nocrlf:
    call    BDOS
    pop     ix                          ;restore callers

    ret
