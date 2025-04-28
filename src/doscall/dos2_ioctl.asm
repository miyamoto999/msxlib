
    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_ioctl
    PUBLIC _dos2_ioctl
    PUBLIC ___dos2_ioctl
    EXTERN msxlib_doscall

; /* デバイスのI/O制御 */
; uint8_t __LIB__ dos2_ioctl(uint8_t handle, uint8_t sub_code, int16_t *prm_ret) __smallc;
; sp + 2    prm_ret
; sp + 4    sub_code
; sp + 6    handle
dos2_ioctl:
_dos2_ioctl:
___dos2_ioctl:
    ; sub_codeとりだし
    ld hl,4
    add hl,sp

    ld a,(hl)
    inc hl
    inc hl

    ; handleの取り出し
    ld b,(hl)

    ; prm_retの取り出し
    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld h,(hl)
    ld l,c

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_IOCTL
    call msxlib_doscall

    ld hl,2
    add hl,sp

    ld c,a
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ld (hl),e
    inc hl
    ld (hl),d

    ld l,c

    ret