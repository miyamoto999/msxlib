    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_parse
    PUBLIC _dos2_parse
    PUBLIC ___dos2_parse
    EXTERN msxlib_doscall


; /* パス名の解析 */
; uint8_t dos2_parse(const char *path, uint8_t vol_flag, char **last_str, char **start_filename, uint8_t *analysis_flag, uint8_t *drv);
dos2_parse:
_dos2_parse:
___dos2_parse:
    ld hl,10
    add hl,sp

    ld b,(hl)
    inc hl
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_PARSE
    call msxlib_doscall

    or a
    jr nz,ERR_RET

    ; ld ix,2
    ; add ix,sp

    ; push hl
    ; ld l,(ix+0)
    ; ld h,(ix+1)
    ; ld (hl),c

    ; ld l,(ix+2)
    ; ld h,(ix+3)
    ; ld (hl),b

    ; ld l,(ix+6)
    ; ld h,(ix+7)
    ; ld (hl),e
    ; inc hl
    ; ld (hl),d
    ; pop hl
    ; ex hl,de

    ; ld l,(ix+4)
    ; ld h,(ix+5)
    ; ld (hl),e
    ; inc hl
    ; ld (hl),d

    push de
    push hl
    ld hl,6
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ex hl,de
    ld (hl),c

    ex hl,de
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ex hl,de
    ld (hl),b

    ex hl,de
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ex hl,de
    pop bc
    ld (hl),c
    inc hl
    ld (hl),b

    ex hl,de
    ld e,(hl)
    inc hl
    ld d,(hl)
    ex hl,de
    pop de
    ld (hl),e
    inc hl
    ld (hl),d

    ;;; どっちが速いんやろーw

    ld l,a

    ret

ERR_RET:
    ld l,a
    ret
