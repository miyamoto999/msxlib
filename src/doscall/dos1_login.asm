    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_login
    PUBLIC _dos1_login
    PUBLIC ___dos1_login


; /* ログインベクタの取得 */
; uint16_t dos1_login();
dos1_login:
_dos1_login:
___dos1_login:
    ld c,_LOGIN
    jp BDOS
