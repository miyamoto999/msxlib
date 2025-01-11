# msxlib

[msx0_httpget](https://github.com/miyamoto999/msx0_httpget)や非公開のツールを作る時に作ったZ88DKのCコンパイラで使えるMSX用の関数などを集めたライブラリになります。

# ビルド方法

Z88DKのインストールされたUNIX系のOS上で

~~~bash
./build.sh
~~~

を実行すると完了し、./libsディレクトリにasmroutine.lib、bios.lib、doscall.lib、dskcall.lib、iot.lib、msxlib.lib、slot.lib、vdp.libが生成されます。


## ソースツリーの簡単な説明
~~~
.
|-- README.md                       このファイル
|-- doc
|   `-- memo.md                     開発メモ？のようなもの
|-- include
|   `-- msxlib                      C言語のヘッダファイル
|       `-- asm                     asmのヘッダファイル
|-- libs                            ビルド後、ライブラリファイルが格納される
|-- sample
|   `-- msx0                        MSX0用のサンプルプログラム
|       |-- clrrsd                      レジーム機能のセーブデータを削除するコマンド
|       |-- iotget                      IOTノードの値の取得
|       |-- iotput                      IOTノードの値の設定
|       |-- tree                        IOTノードツリーを表示
|       `-- wifislct                    WiFiの接続先を自動的に切り替える
|-- src                             ソースファイル
|   |-- asmroutine                  アセンブラ用のルーチン
|   |-- bcdf                        MSXのBCD実数を文字列やdouble型への変換
|   |-- bfile                       バッファー℃ファイル入出力
|   |-- bios                        MSX-BIOSを呼び出す
|   |   |-- msxmain_dct_*.asm           BASIC上のマシン語からMAIN-BIOSを呼び出す関数
|   |   |-- msxmain_dos_*.asm           DOS上からMAIN-BIOSを呼び出す関数
|   |   |-- msxsub_dct_*.asm            BASIC上のマシン語からSUB-BIOSを呼び出す関数
|   |   `-- msxsub_dos_*.asm            DOS上からMAIN-BIOSを呼び出す関数
|   |-- doscall
|   |   |-- dos1_*.asm              DOS1のファンクションコールを呼び出す関数
|   |   |-- dos2_*.asm              DOS2のファンクションコールを呼び出す関数          
|   |   `-- dos_scode.asm           自作のZ80エミュレータの終了コードを設定するファンクションコールを呼び出す関数
|   |-- dskcall
|   |   |-- dsk1_*.asm              DOS1のファンクションコールをBASIC上のマシン語から呼び出す関数
|   |   `-- dsk2_*.asm              DOS1のファンクションコールをBASIC上のマシン語から呼び出す関数
|   |-- iot                         MSX0のIOT関係の関数
|   |-- net                         MSX0のネットワーク(TCP)通信を行う関数
|   |-- rbuf                        リングバッファ
|   |-- slot                        インタースロットコール
|   |-- vdp                         VDP操作関係の関数
|   `-- *.asm, *.c                  その他のソース
|-- tests                           テストプログラム
`-- tools                           ビルドで使うツール
~~~

各関数やサブルーチンの説明は別のファイルで行う。
- [iot関係](doc/iot.md)