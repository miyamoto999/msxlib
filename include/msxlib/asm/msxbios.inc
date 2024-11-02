;;;; インタースロットコール
;   RDSLT 指定スロットの指定アドレスを読む
MSXMAIN_RDSLT       equ     0x000c
; CALSLT 指定スロットの指定アドレスをコール
MSXMAIN_CALSLT      equ     0x001c
;;;;;;;;

; SNSMAT キーマトリックスの指定行を読み出す
MSXMAIN_SNSMAT      equ     0x0141

; KILBUF キー入力バッファをクリア
MSXMAIN_KILBUF      equ     0x0156

; CHGMOD SCREENモードの切り替え
MSXMAIN_CHGMOD      equ     0x005f

; CHGCLR 画面の色を変える
MSXMAIN_CHGCLR      equ     0x0062

; GTPAD 各種入出力機器の状態取得
MSXMAIN_GTPAD       equ     0x00db

; SUB ROMの指定アドレスをコールする
MSXMAIN_EXTROM      equ     0x015f

; NMI
MSXMAIN_NMI         equ     0x0066

; 画面クリア
MSXMAIN_CLS         equ     0x00c3

; GRPPRT グラフィック画面に文字を表示します。
MSXMAIN_GRPPRT      equ     0x008d

; CHSNS キーボードバッファの残りをチェック
MSXMAIN_CHSNS       equ     0x009c

; CHGET キーボードバッファから1文字入力する。
MSXMAIN_CHGET       equ     0x009f

; CHPUT 文字を1文字出力する。
MSXMAIN_CHPUT       equ     0x00a2

; INIPLT(SUB) パレットを初期化
MSXSUB_INIPLT       equ     0x0141

; CHGMOP スクリーンモードを変更します。
MSXSUB_CHGMOD  equ     0x00d1

; CHGMDP スクリーンモードを変更します。(パレットも初期化)
MSXSUB_CHGMDP  equ     0x01b5

; 画面クリア
MSXSUB_CLSSUB  equ     0x0115

; REDCLK CLOCK-ICのデータ読み出し
MSXSUB_REDCLK  equ     0x01f5

; KNJPRT グラフィック画面に漢字を表示する
MSXSUB_KNJPRT  equ     0x01bd

; SETPLT パレットを設定する
MSXSUB_SETPLT  equ     0x014d
