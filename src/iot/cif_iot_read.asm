    SECTION code_user
    PUBLIC iot_read
    PUBLIC _iot_read
    PUBLIC ___iot_read
    GLOBAL as_strlen,as_iot_read

; リングバッファにデータがある場合はリングバッファから、ない場合はnodeからデータを取得(C言語IF)
; int iot_read(RBUF *rbuf, const char *node, char *buf, int size);
iot_read:
_iot_read:
___iot_read:
    ld hl,2
    add hl,sp

    ; sizeを取り出す
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl
    push bc
    pop iy

    ; bufを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; nodeをいったんスキップ
    inc hl
    inc hl
    ; rbufを取り出す
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    push ix
    push hl
    pop ix

    ; nodeを取り出す
    ld hl,8
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push hl
;     ld b,0
; loop4:
;     ld a,(hl)
;     inc b
;     inc hl
;     or a
;     jr nz,loop4
    call as_strlen
    
    pop hl
    ; dec b

    call as_iot_read

    pop ix
    ret

