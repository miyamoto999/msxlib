; MAIN ROMのスロット番号
MSXWORK_EXPTBL      equ     0xfcc1
; SUB ROMのスロット番号
MSXWORK_EXBRSA      equ     0xfaf8

; キークリック音 0:off 0以外:on
MSXWORK_CLIKSW      equ     0xf3db

; 前景色
MSXWORK_FORCLR      equ     0xf3e9
; 背景色
MSXWORK_BAKCLR      equ     0xf3ea
; 周辺色
MSXWORK_BDRCLR      equ     0xf3eb

; NMIのフック
MSXWORK_H_NMI       equ     0xfdd6

; VDPレジスタ0の値を保存
MSXWORK_RG0SAV      equ     0xf3df
; VDPレジスタ1の値を保存
MSXWORK_RG1SAV      equ     0xf3e0
; VDPレジスタ2の値を保存
MSXWORK_RG2SAV      equ     0xf3e1
; VDPレジスタ3の値を保存
MSXWORK_RG3SAV      equ     0xf3e2
; VDPレジスタ4の値を保存
MSXWORK_RG4SAV      equ     0xf3e3
; VDPレジスタ5の値を保存
MSXWORK_RG5SAV      equ     0xf3e4
; VDPレジスタ6の値を保存
MSXWORK_RG6SAV      equ     0xf3e5
; VDPレジスタ7の値を保存
MSXWORK_RG7SAV      equ     0xf3e6

; VDPレジスタ8の値を保存
MSXWORK_RG8SAV      equ     0xffe7
; VDPレジスタ9の値を保存
MSXWORK_RG9SAV      equ     0xffe8
; VDPレジスタ10の値を保存
MSXWORK_RG10SAV     equ     0xffe9
; VDPレジスタ11の値を保存
MSXWORK_RG11SAV     equ     0xffea
; VDPレジスタ12の値を保存
MSXWORK_RG12SAV     equ     0xffeb
; VDPレジスタ13の値を保存
MSXWORK_RG13SAV     equ     0xffec
; VDPレジスタ14の値を保存
MSXWORK_RG14SAV     equ     0xffed
; VDPレジスタ15の値を保存
MSXWORK_RG15SAV     equ     0xffee
; VDPレジスタ16の値を保存
MSXWORK_RG16SAV     equ     0xffef
; VDPレジスタ17の値を保存
MSXWORK_RG17SAV     equ     0xfff0
; VDPレジスタ18の値を保存
MSXWORK_RG18SAV     equ     0xfff1
; VDPレジスタ19の値を保存
MSXWORK_RG19SAV     equ     0xfff2
; VDPレジスタ20の値を保存
MSXWORK_RG20SAV     equ     0xfff3
; VDPレジスタ21の値を保存
MSXWORK_RG21SAV     equ     0xfff4
; VDPレジスタ22の値を保存
MSXWORK_RG22SAV     equ     0xfff5
; VDPレジスタ23の値を保存
MSXWORK_RG23SAV     equ     0xfff6
; VDPレジスタ25の値を保存
MSXWORK_RG25SAV     equ     0xfffa
; VDPレジスタ26の値を保存
MSXWORK_RG26SAV     equ     0xfffb
; VDPレジスタ27の値を保存
MSXWORK_RG27SAV     equ     0xfffc
; ロジカルオペレーションコード
MSXWORK_LOGOPR      equ     0xfb02
; GXPOS X座標
MSXWORK_GXPOS       equ     0xfcb3
; GYPOS Y座標
MSXWORK_GYPOS       equ     0xfcb5
; GRPACX グラフィックアキュムレータX
MSXWORK_GRPACX      equ     0xfcb7
; GRPACX グラフィックアキュムレータY
MSXWORK_GRPACY      equ     0xfcb9
; GRPHED グラフィック文字を出すときのフラグ 
MSXWORK_GRPHED      equ     0xfca6
; SCRMOD スクリーンモード番号
MSXWORK_SCRMOD      equ     0xfcaf
; OLDSCR スクリーンモードの保存場所
MSXWORK_OLDSCR      equ     0xfcb0