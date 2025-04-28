    include "msxlib/asm/msxdos.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_clib
    PUBLIC fgetc_cons_dos
    PUBLIC _fgetc_cons_dos
    PUBLIC ___fgetc_cons_dos
    EXTERN __CLIB_FIRMWARE_KEYBOARD_CLICK

fgetc_cons_dos:
_fgetc_cons_dos:
___fgetc_cons_dos:
    ld c,_INNOE
    call BDOS

    cp      13
    jr      nz, not_return
    ld      a, 10
not_return:

    ld      l, a
    ld      h, 0
    ret

    SECTION code_crt_init

    ld      a, __CLIB_FIRMWARE_KEYBOARD_CLICK
    cp      -1
    jr      z, no_set_click
    ld      (MSXWORK_CLIKSW), a
no_set_click:

    ld      a, 1
    ld      (MSXWORK_CSRSW), a                  ; disable cursor, it could put garbage on screen in gfx mode


