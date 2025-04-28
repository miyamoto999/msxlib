    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_alloc
    PUBLIC _dos1_alloc
    PUBLIC ___dos1_alloc
    EXTERN msxlib_doscall

; /* アロケーション情報の取得 */
; void dos1_alloc(uint8_t drv_num, uint8_t *sec, uint16_t *sec_size, uint16_t *cluster, uint16_t *unused_cluster, uint16_t *dpb_pointer, uint16_t *fat_pointer);
;
;       sp + 2      *fat_pointer        IY
;       sp + 4      *dpb_pointer        IX
;       sp + 6      *unused_cluster     HL
;       sp + 8      *cluster            DE
;       sp + 10     *sec_size           BC    
;       sp + 12     *sec                A
;       sp + 14     drv_num
;
dos1_alloc:
_dos1_alloc:
___dos1_alloc:
    ld hl,14
    add hl,sp

    push ix

    ld e,(hl)
    ld c,_ALLOC
    call msxlib_doscall

    ; 各レジスタをバックアップ
    ld (REG_IX),ix
    ld (REG_IY),iy
    ld (REG_HL),hl
    ld (REG_DE),de
    ld (REG_A),a

    ; ixをpushしているのでオフセットは+2
    ld ix,2
    add ix,sp

    ; *fat_pointer
    ld a,(ix + 2)
    ld h,(ix + 2 + 1)
    ld l,a
    ld de,(REG_IY)
    ld (hl),e
    inc hl
    ld (hl),d

    ; *dpb_pointer
    ld a,(ix + 4)
    ld h,(ix + 4 + 1)
    ld l,a
    ld de,(REG_IX)
    ld (hl),e
    inc hl
    ld (hl),d

    ; *unused_cluster
    ld a,(ix + 6)
    ld h,(ix + 6 + 1)
    ld l,a
    ld de,(REG_HL)
    ld (hl),e
    inc hl
    ld (hl),d

    ; *cluster
    ld a,(ix + 8)
    ld h,(ix + 8 + 1)
    ld l,a
    ld de,(REG_DE)
    ld (hl),e
    inc hl
    ld (hl),d

    ; *sec_size
    ld a,(ix + 10)
    ld h,(ix + 10 + 1)
    ld l,a
    ld (hl),c
    inc hl
    ld (hl),b

    ; *sec
    ld a,(ix + 12)
    ld h,(ix + 12 + 1)
    ld l,a
    ld a,(REG_A)
    ld (hl),a

    pop ix

    ret

    SECTION data_user

REG_A:  ds 2
REG_DE: ds 2
REG_HL: ds 2
REG_IX: ds 2
REG_IY: ds 2