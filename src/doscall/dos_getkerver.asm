    include "msxlib/asm/msxdos.inc"

    SECTION code_user
    PUBLIC dos_getkerver
    PUBLIC _dos_getkerver
    PUBLIC ___dos_getkerver

    EXTERN msxlib_doscall

dos_getkerver:
_dos_getkerver:
___dos_getkerver:
    ld a,(MSXDOS_KERVERSION)
    ld l,a
    ret

    SECTION code_crt_init

    ld a,0xff
    ld c,_DOSVER
    call msxlib_doscall
    and a
    jr nz,not_msxdos
    ld a,b
    cp 1
    jp P,msxdos_version2p
msxdos_versin1:
    ld a,1
msxdos_version2p:
    ld (MSXDOS_KERVERSION),a
not_msxdos:


    SECTION bss_user
MSXDOS_KERVERSION:
    db 0