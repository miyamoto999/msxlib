ExTERN __bdos

BDOS:       equ     __bdos

;BDOS:       equ     0x0005      ; BDOSコールのアドレス
;BDOS_DSK:   equ     0xf37d      ; BDISコール(DISK BASIC時)のアドレス
WBOOT:	    equ 	0x0000      ; WBOOTのアドレス
DMA:	    equ     0x0080      ; デフォルトのDMAアドレス
DTA:	    equ     DMA         ; デフォルトのDMAアドレス
TPA:        equ     0x0100      ; TPAのアドレス
DEF_FCB1:   equ     0x005c      ; FCB1のアドレス
DEF_FCB2:   equ     0x006c      ; FCB1のアドレス

; DOS1、CP/Mのシステムコール
_TERM0:     equ     0x00        ; プログラム終了システムコール番号(CP/M)
_CONIN:     equ     0x01        ; コンソール入力システムコール番号(CP/M)
_CONOUT:    equ     0x02        ; コンソール1文字出力システムコール番号(CP/M)
_AUXIN:     equ     0x03        ; 補助入力システムコール番号(CP/M)
_AUXOUT:    equ     0x04        ; 補助出力システムコール番号(CP/M)
_LSTOUT:    equ     0x05        ; プリンタ出力システムコール番号(CP/M)
_DIRIO:     equ     0x06        ; 直接コンソールI/Oシステムコール番号(CP/M)
_DIRIN:     equ     0x07        ; 直接コンソール入力システムコール番号
_INNOE:     equ     0x08        ; エコーなしコンソール入力システムコール番号
_STROUT:    equ     0x09        ; コンソール文字列出力システムコール番号(CP/M)
_BUFIN:     equ     0x0a        ; バッファ行入力システムコール番号(CP/M)
_CONST:     equ     0x0b        ; コンソールステータスシステムコール番号(CP/M)
_CPMVER:    equ     0x0c        ; バージョンの取得システムコール番号(CP/M)
_DSKRST:    equ     0x0d        ; ディスクリセットシステムコール番号(CP/M)
_SELDSK:    equ     0x0e        ; ディスクの選択システムコール番号(CP/M)
_FOPEN:     equ     0x0f        ; ファイルのオープンシステムコール番号(CP/M)
_FCLOSE:	equ 	0x10        ; ファイルクローズシステムコール番号(CP/M)
_SFIRST:    equ     0x11        ; 最初のエントリの検索[FCB]システムコール番号(CP/M)
_SNEXT:     equ     0x12        ; 次のエントリの検索[FCB]システムコール番号(CP/M)
_FDEL:      equ     0x13        ; ファイルの削除[FCB]システムコール番号(CP/M)
_RDSEQ:     equ     0x14        ; シーケンシャルな読み出し[FCB]システムコール番号(CP/M)
_WRSEQ:		equ     0x15        ; シーケンシャル書き込み[FCB]システムコール番号(CP/M)
_FMAKE:		equ     0x16        ; ファイルの作成[FCB]システムコール番号(CP/M)
_FREN:      equ     0x17        ; ファイル名の変更[FCB]システムコール番号(CP/M)
_LOGIN:     equ     0x18        ; ログインベクタの取得システムコール番号(CP/M)
_CURDRV:    equ     0x19        ; カレントドライブの取得システムコール番号(CP/M)
_SETDTA:    equ     0x1a        ; ディスク転送アドレスのセットシステムコール番号(CP/M)
_ALLOC:     equ     0x1b        ; アロケーション情報の取得システムコール番号

_RDRND:     equ     0x21        ; ランダムな読み出し[FCB]システムコール番号
_WRRND:     equ     0x22        ; ランダムな書き込み[FCB]システムコール番号(CP/M)
_FSIZE:     equ     0x23        ; ファイルサイズの獲得[FCB]システムコール番号(CP/M)
_SETRND:    equ     0x24        ; ランダムレコードのセット[FCB]システムコール番号(CP/M)

_WRBLK:     equ     0x26        ; ランダムなブロックの書き込み[FCB]システムコール番号
_RDBLK:     equ     0x27        ; ランダムなブロックの読み出し[FCB]システムコール番号
_WRZER:     equ     0x28        ; ゼロフィルを行うランダムな書き込み[FCB]システムコール番号(CP/M)

_GDATE:     equ     0x2a        ; 日付の獲得システムコール番号
_SDATE:     equ     0x2b        ; 日付のセットシステムコール番号
_GTIME:     equ     0x2c        ; 時刻の獲得システムコール番号
_STIME:     equ     0x2d        ; 時刻のセットシステムコール番号
_VERIFY:    equ     0x2e        ; ベリファイフラグのセット・リセットシステムコール番号
_RDABS:     equ     0x2f        ; アブソリュートなセクタの読み出しシステムコール番号
_WRABS:     equ     0x30        ; アブソリュートなセクタの書き込みシステムコール番号

; DOS2のシステムコール
_DPARM:     equ     0x31        ; ディスクパラメータの獲得システムコール番号

_FFIRST:    equ     0x40        ; 最初のエントリの検索システムコール番号
_FNEXT:     equ     0x41        ; 次のエントリの検索システムコール番号
_FNEW:      equ     0x42        ; 新しいエントリの検索システムコール番号
_OPEN:      equ     0x43        ; ファイルハンドルのオープンシステムコール番号
_CREATE:    equ     0x44        ; ファイルハンドルの作成システムコール番号
_CLOSE:     equ     0x45        ; ファイルハンドルのクローズシステムコール番号
_ENSURE:    equ     0x46        ; ファイルハンドルの確保システムコール番号
_DUP:       equ     0x47        ; ファイルハンドルの複製システムコール番号
_READ:      equ     0x48        ; ファイルハンドルからの読み出しシステムコール番号
_WRITE:     equ     0x49        ; ハンドルへの書き込みシステムコール番号
_SEEK:      equ     0x4a        ; ファイルハンドルポインタの移動システムコール番号
_IOCTL:     equ     0x4b        ; デバイスのI/O制御システムコール番号
_HTEST:     equ     0x4c        ; ファイルハンドルのテストシステムコール番号
_DELETE:    equ     0x4d        ; ファイル・サブディレクトリの削除システムコール番号
_RENAME:    equ     0x4e        ; ファイル名・サブディレクトリ名の変更システムコール番号
_MOVE:      equ     0x4f        ; ファイル・サブディレクトリの移動システムコール番号
_ATTR:      equ     0x50        ; ファイル属性の獲得・セットシステムコール番号
_FTIME:     equ     0x51        ; ファイルの日付および時刻の獲得・セットシステムコール番号
_HDELETE:   equ     0x52        ; ファイルハンドルの削除システムコール番号
_HRENAME:   equ     0x53        ; ファイルハンドルの名前の変更システムコール番号
_HMOVE:     equ     0x54        ; ファイルハンドルの移動システムコール番号
_HATTR:     equ     0x55        ; ファイルハンドルの属性の獲得・セットシステムコール番号
_HFTIME:    equ     0x56        ; ファイルハンドルの日付および時刻の獲得・セットシステムコール番号
_GETDTA:    equ     0x57        ; ディスク転送アドレスの獲得システムコール番号
_GETVFY:    equ     0x58        ; ベリファイフラグ設定の獲得システムコール番号
_GETCD:     equ     0x59        ; カレントディレクトリの獲得システムコール番号
_CHDIR:     equ     0x5a        ; カレントディレクトリの変更システムコール番号
_PARSE:     equ     0x5b        ; パス名の解析システムコール番号
_PFILE:     equ     0x5c        ; ファイル名の解析システムコール番号
_CHKCHR:    equ     0x5d        ; 文字の検査システムコール番号
_WPATH:     equ     0x5e        ; 完全なパス文字列の獲得システムコール番号
_FLUSH:     equ     0x5f        ; ディスクバッファのフラッシュシステムコール番号
_FORK:      equ     0x60        ; 子プロセスの起動システムコール番号
_JOIN:      equ     0x61        ; 親プロセスに戻るシステムコール番号
_TERM:      equ     0x62        ; エラーコードを伴った終了システムコール番号
_DEFAB:     equ     0x63        ; アボート終了ルーチンの定義システムコール番号
_DEFER:     equ     0x64        ; ディスクエラー処理ルーチンの定義システムコール番号
_ERROR:     equ     0x65        ; 直前のエラーコードの獲得システムコール番号
_EXPLAIN:   equ     0x66        ; エラーコードの説明システムコール番号
_FORMAT:    equ     0x67        ; ディスクのフォーマットシステムコール番号
_RAMD:      equ     0x68        ; RAMディスクの作成あるいは消去システムコール番号
_BUFFER:    equ     0x69        ; セクタバッファの割り付けシステムコール番号
_ASSIGN:    equ     0x6a        ; 論理ドライブの割り当てシステムコール番号
_GEENV:     equ     0x6b        ; 環境変数の獲得システムコール番号
_SENV:      equ     0x6c        ; 環境変数のセットシステムコール番号
_FENV:      equ     0x6d        ; 環境変数の検索システムコール番号
_DSKCHK:    equ     0x6e        ; ディスク検査ステータスの獲得・セットシステムコール番号
_DOSVER:    equ     0x6f        ; MSX-DOSのバージョン番号の獲得システムコール番号
_REDIR:     equ     0x70        ; リダイレクションの状態の獲得・セットシステムコール番号

;;; emmy80で拡張したシステムコール番号
_SCODE:     equ     0x80        ; プロセス終了コードのセットシステムコール番号

