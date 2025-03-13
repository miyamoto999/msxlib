; MAC_VDP_SET_REG
;
; VDPレジスタに値をセットする
;   c <- _g_msxvdp_write_port_1の値を入れておく
;   reg <- VDPレジスタ番号
;   val <- セットする値
; 破壊レジスタ
;   a,f
MACRO MAC_VDP_SET_REG reg, val
    ld a,val
    ; valをIOポートに書き出す
    out (c),a

    ; reg | 0x80を書き出す
    ld a,0x80
    or reg
    out (c),a
ENDM

; MAC_VDP_SET_REG_INDIRECT
;
; 間接指定のVDPレジスタ番号を設定する。
;   c <- _g_msxvdp_write_port_1の値を入れておく
;   reg <- VDPレジスタ番号(最上位ビットを立てると
;           レジスタ番号が非インクリメントになる)
; 破壊レジスタ
;   a,f
MACRO MAC_VDP_SET_REG_INDIRECT reg
    MAC_VDP_SET_REG 17, reg
ENDM

; MAC_VDP_GET_STATUS
; 
; VDPステータスレジスタの値を取得する。
; このマクロは割り込み禁止状態で使用する必要がある。
;
; 入力
;   z80reg <- VDPステータスレジスタの値をセットするZ80レジスタ
;   st_reg <- VDPステータスレジスタ番号
; 出力
;   z80reg <- VDPステータスレジスタの値
; 破壊レジスタ
;   a,f,c
MACRO MAC_VDP_GET_STATUS z80reg, st_reg
    push af    
    ld a,(_g_msxvdp_write_port_1)
    ld c,a
    pop af
    ; R#15にステータスレジスタ番号を設定
    MAC_VDP_SET_REG 15, st_reg
    ; ステータスレジスタの値を読み込む
    ld a,(_g_msxvdp_read_port_1)
    ld c,a
    in z80reg,(c)

    ld a,(_g_msxvdp_write_port_1)
    ld c,a
    ; R#15にステータスレジスタ番号を設定
    MAC_VDP_SET_REG 15, 0

    ; ld a,(_g_msxvdp_read_port_1)
    ; ld c,a
    ; in z80reg,(c)
ENDM