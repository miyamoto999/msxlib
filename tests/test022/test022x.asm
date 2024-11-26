            include "msxlib/asm/msxdos.inc"

            org 0x0100

;;;;;;;;;;;
            SECTION code_user

            LD SP,(BDOS + 1)
            
            ; 開始メッセージを表示
            ld de,MSG0
            ld c,_STROUT
            call BDOS

            call PRINT_COUNT        ;0

            ; hoge.txtを作成
            ;; FCBを準備
            ld hl,FCB1
            call FCB_CLEAR

            ld hl,HOGE_TXT
            ld de,FCB1
            ld bc,12
            ldir
            
            ld de,FCB1
            ld c,_FMAKE
            call BDOS

            ld de,FCB1
            ld c,_WRSEQ
            call BDOS

            ld de,FCB1
            ld c,_FCLOSE
            call BDOS

            call PRINT_COUNT        ;1

            ; hoge2.txtを作成
            ;; FCBを準備
            ld hl,FCB2
            call FCB_CLEAR

            ld hl,HOGE2_TXT
            ld de,FCB2
            ld bc,12
            ldir
            
            ld de,FCB2
            ld c,_FMAKE
            call BDOS

            ld de,FCB2
            ld c,_WRSEQ
            call BDOS

            ld de,FCB2
            ld c,_FCLOSE
            call BDOS

            ; ためしに_DSKRSTしてみる
            ; ld c,_DSKRST
            ; call BDOS

            call PRINT_COUNT        ;2

            ld hl,FCB3
            call FCB_CLEAR

            ;; oldファイル名をコピー
            ld hl,OLDNAME
            ld de,FCB3
            ld bc,12
            ldir

            call PRINT_COUNT        ;3

            ;; newファイル名をコピー
            ld hl,NEWNAME
            ld de,FCB3 + 16
            ld bc,12
            ldir

            call PRINT_COUNT        ;4

            ; _FRENを実行
            ld de,FCB3
            ld c,_FREN
            call BDOS

            call PRINT_COUNT        ;5

            jp 0

PRINT_COUNT:
            push af
            push bc
            push de

            ld de,MSG1
            ld c,_STROUT
            call BDOS

            ld hl,MSG1
            inc (HL)
            
            pop de
            pop bc
            pop af
            ret

FCB_CLEAR:
            ;; FCBを初期化
            xor a
            ld b,37
LOOP1:      ld (hl),a
            inc hl
            djnz LOOP1
            ret

;;;;;;
            SECTION data_user
FCB1:       ds 37
FCB2:       ds 37
FCB3:       ds 37
OLDNAME:    db 0x00,"H???????TXT"
NEWNAME:    db 0x00,"A???????BIN"
HOGE_TXT:   db 0x00,"HOGE    TXT"
HOGE2_TXT:  db 0x00,"HOGE2   TXT"
MSG0:       db "start", 0x0d, 0x0a,"$"
MSG1:       db "0", 0x0d, 0x0a, "$"