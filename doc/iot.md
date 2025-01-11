# IOT関係

MSX0のIOTの操作関係を実装したものである。

## iot_geti() IOTノードから整数値の取得(C言語)
IOTノードから整数値を取得します。
### 呼び出し方法
    short iot_geti(const char *node);

    const char *node        IOTノードパスの文字列
### 戻り値
    nodeで指定したパスの値
### ソース
    ./iot/cif_iot_geti.asm

## as_iot_geti IOTノードから整数値の取得(アセンブラ)
IOTノードから整数値を取得します。
### 呼び出し方法
    HL <- IOTノードパスの文字列の先頭アドレス
    B <- IOTノードパスの文字数(バイト数)

    CALL as_iot_geti    

### 戻り値
    HL <- IOTノードの値
### ソース
    ./iot/as_iot_geti.asm


