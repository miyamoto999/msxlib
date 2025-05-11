    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_ftime
    PUBLIC _dos2_ftime
    PUBLIC ___dos2_ftime
    EXTERN msxlib_doscall

; /* ファイルの日付および時刻の設定または取得 */
; uint8_t __LIB__ dos2_ftime(char *filename, uint8_t set_flag, uint16_t *time, uint16_t *date) __smallc;
;
; sp + 2        *date
; sp + 4        *time
; sp + 6        set_flag
; sp + 8        filename
;
dos2_ftime:
_dos2_ftime:
___dos2_ftime:
    ld hl,2
    add hl,sp

    push ix
    ; dateを取り出す
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld a,(bc)
    ld e,a
    inc bc
    ld a,(bc)
    ld d,a

    push de

    ; timeを取り出す
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld a,(bc)
    ld e,a
    inc bc
    ld a,(bc)
    ld d,a

    push de

    ; set_flagを取り出す
    ld a,(hl)
    inc hl
    inc hl

    ; filenameを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)

    pop ix
    pop hl

    ld c,_FTIME
    call msxlib_doscall

    pop ix

    push af
    push hl

    ld hl,4+4
    add hl,sp

    ; timeに値を設定
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld a,e
    ld (bc),a
    inc bc
    ld a,d
    ld (bc),a

    pop de

    ld hl,4
    add hl,sp
    ; dateに値を設定
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld a,e
    ld (bc),a
    inc bc
    ld a,d
    ld (bc),a

    pop af
    ld l,a
    
    ret