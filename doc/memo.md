# メモ

## 2025/4/27
1日30分でもいいから必ずプログラムをいじるってのをしないといかんな〜

## 2025/4/12
msxvdp_pork()、msxvdp_peek()もアセンブリで書き直なおして、CPU側のメモリを一気に読み書きする関数(msxvdp_read()、msxvdp_write()みたいな？)も追加しようか。これがないとアセンブリで書き直すだけじゃあんまり意味がないと思う。

## 2025/3/13
いろいろかなり変更しそうなのでバックアップ目的で一旦このタイミングでコミットする。

## 2025/3/12
### z88dk関連(ここに書くことじゃないような気がするけど(^^;))
printfの"%f"が使えない件は、-pragma-includeで指定するpragmaファイルに
~~~
#pragma printf="%f"
~~~
のように描くておくと、リンク時に-pragma-define:CLIB_OPT_PRINTF=0x.....というオプションを付けなくてもいい。コの方がCLIB_OPT_PRINTFを指定するよりも指定しやすい。"%d"も使えるようにするには"%d %f"と書く。

## 2025/3/8
### z88dk関連(ここに書くことじゃないような気がするけど(^^;))
2025/1/6に書いたprintfの"%f"が使えないのって"lib/crt/classic/crt_runtime_selection.inc"に書いてあるようにリンク時に-pragma-define:CLIB_OPT_PRINTF=0x.....というオプションを付ければいい。

DOS2でcreat()、open()、write()するとエラーになるんだよね〜。z88dkのソースみるとcreat()でリードオンリーで開いてるっぽい。また直してプルリクエストださんといかんな〜。要調査(^^;)

DOS2のリダイレクションがきかない(^^;) z88dkのputcharだったかは1文字出力のBIOSをよんでるからそのせいかもしれない。要調査(^^;)

z88dk、わからんとことかいろいろあるなー

### msxlib関連
HMMCコマンドを呼び出す関数をC言語ベースで実装したけど、アセンブラ中心で書くと速くなるかもしれない。z88dk関連で書いたようにいろいろあるんで、その前にopen()、read()などの代わりのものを実装しようかと思う。

## 2025/1/8
2025/1/6に関係ないけど、と書いた問題は浮動小数点演算の処理でZ80の未定義命令が使用されていて、Z80エミュレータで未定義命令の実装はしていたけれどバグっていたという結果。

## 2025/1/6
zccでソースコードからオブジェクトを作ってリンクして実行ファイルを生成すると、printf()で"%f"が使えない。
ソースコードから直接実行ファイルを生成すると、printf()で"%f"が使える。
どうすればいいんだろう。

関係ないが未公開のZ80エミュレータで浮動小数点演算を使用しているプログラムが実行できないことがわかった(^^;)