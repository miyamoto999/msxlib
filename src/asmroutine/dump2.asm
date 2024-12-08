
            SECTION code_user
            GLOBAL DISPHEX, OUT_SPC, OUT_CRLF
            PUBLIC DUMP2
            
; メモリダンプ
;	HL:スタートアドレス
;	BC:バイト数
;   DE:表示スタートアドレス
DUMP2:      ; アドレスを出力
            ld a,d
            push bc
            push hl
            push de
            call DISPHEX
            pop de
            ld a,e
            push de
            call DISPHEX
            pop de
            pop hl
            pop bc

            ; 8バイト分データを表示
            ld a, 8
            ld (COUNTER8), a

LOOP:
            push bc
            push de
            push hl
            call OUT_SPC
            pop hl
            ld a,(hl)
            push hl
            call DISPHEX
            pop hl
            pop de
            pop bc

            ; アドレスを進める
            inc hl
            inc de

            ; 全データカウンタを減らす
            dec bc
            ; 全データを表示したら(前データカウンタが0なら)、終了
            ld a, b
            or c
            ret z

            ; 8バイト表示カウンタを減らす
            ld a, (COUNTER8)
            dec a
            ld (COUNTER8), a
            ; まだ、8バイト分表示してないなら、LOOPにジャンプ
            jr nz, LOOP

            ; 8バイト分表示したなら、CRLFを表示してアドレス部分から表示するようにジャンプ
            push hl
            push bc
            push de
            call OUT_CRLF
            pop de
            pop bc
            pop hl

            jr DUMP2

            ret

            SECTION data_user
COUNTER8:   db 0