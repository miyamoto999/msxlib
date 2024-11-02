    SECTION code_user
    PUBLIC as_strlen

; 文字数をカウント
;   hl <- 文字列の先頭アドレス
;
; 戻り値
;   b <- 文字数
;
as_strlen:
    ld b,0
LOOP:
    ld a,(hl)
    or a
    ret z

    inc b
    inc hl
    jr LOOP
