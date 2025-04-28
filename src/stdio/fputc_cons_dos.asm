    include "msxlib/asm/msxdos.inc"

    SECTION code_clib
    PUBLIC  fputc_cons_dos
    PUBLIC _fputc_cons_dos
    PUBLIC ___fputc_cons_dos


fputc_cons_dos:
_fputc_cons_dos:
___fputc_cons_dos:
    ld      hl, 2
    add     hl, sp
    ld      a, (hl)

    push    ix                          ;save callers

    ld      c,_CONOUT
    ld      e,a
    cp      10
    jr      nz, nocrlf

    call BDOS
    ld      e, 13

    ld c,_CONOUT

nocrlf:
    call    BDOS
    pop     ix                          ;restore callers

    ret
