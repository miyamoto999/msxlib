    include "msxlib/asm/iot.inc"


    SECTION code_user
    PUBLIC as_iot_read
    GLOBAL as_iot_node_write,as_rbuf_add_data,as_rbuf_read, as_rbuf_get_size

; nodeからデータを取得
;   hl <- nodeの文字列の先頭アドレス
;   b <- nodeの文字列の文字数
;   de <- データを保存するバッファの先頭アドレス
;   iy <- データ書き込みバッファサイズ
;   ix <- RBUF、リングバッファ
;
; 戻り値
;   hl <- 読み込んだデータ数
;           -1:エラー
;
;
; int iot_read_1(RBUF *rbuf, const char *node, char *buf, int size)
; {
;     int ret = 0;

;     iot_node_write(node);

;     outp(IOT_PORT1, 0xe0);
;     outp(IOT_PORT1, 1);
;     outp(IOT_PORT1, 3);
;     outp(IOT_PORT1, 0x80);

;     int len = inp(IOT_PORT1);       // 試してみたかんじ、64バイト以上にはならないようだ。
;     for(int i = 0; i < len; i++) {
;         if(i >= size) {
;             rbuf_add_data(rbuf, inp(IOT_PORT1));
;         } else {
;             buf[i] = inp(IOT_PORT1);
;             ret++;
;         }
;     }
;     return ret;
; }

iot_read_1:
    push bc
    call as_iot_node_write
    pop bc

    rlca
    jr nc,NEXT

    ld hl,-1

    ret

NEXT:

    ld a,0xe0
    out (IOT_PORT1),a
    ld a,1
    out (IOT_PORT1),a
    ld a,3
    out (IOT_PORT1),a
    ld a,0x80
    out (IOT_PORT1),a

    ld c,0
    in a,(IOT_PORT1)
    or a
    jp z,READ_RET

    ld b,a

    ex hl,de
    push iy
    pop de

loop1:
    ld a,d
    or e
    jr z,loop2

    in a,(IOT_PORT1)
    ld (hl),a
    inc hl
    inc c
    dec de

    djnz loop1
READ_RET:
    ld h,0
    ld l,c
    ret

loop2:
    in a,(IOT_PORT1)
    call as_rbuf_add_data

    djnz loop2
    ld h,0
    ld l,c
    ret

; リングバッファにデータがある場合はリングバッファから、ない場合はnodeからデータを取得
;   hl <- nodeの文字列の先頭アドレス
;   b <- nodeの文字列の文字数
;   de <- データを保存するバッファの先頭アドレス
;   iy <- データ書き込みバッファサイズ
;   ix <- RBUF、リングバッファ
;
; 戻り値
;   hl <- 読み込んだデータ数
;           -1:エラー
;
; int iot_read(RBUF *rbuf, const char *node, char *buf, int size)
; {
;     int ret = 0;

;     if(rbuf_get_size(rbuf) == 0) {
;         ret = iot_read_1(rbuf, node, buf, size);
;     } else {
;         ret = rbuf_read(rbuf, buf, size);
;     }

;     return ret;
; }

as_iot_read:
    push hl
    push de
    call as_rbuf_get_size
    pop de
    ld a,h
    or l
    pop hl
    jp z,iot_read_1

    ex hl,de
    push iy
    pop de
    jp as_rbuf_read

