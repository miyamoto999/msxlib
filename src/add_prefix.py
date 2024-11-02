import sys

def process_lines(prefix):
    buffer = ""  # 連結用のバッファ

    for line in sys.stdin:  # 標準入力から1行ずつ読み込む
        line = line.rstrip()  # 改行や余分な空白を除去
        
        if line.endswith("\\"):  # 行末が '\' の場合
            buffer += line + "\n"
        else:
            buffer += line  # 最後の行も連結
            # 標準出力に prefix を追加して出力
            print(prefix + buffer)
            buffer = ""  # バッファをクリア

if __name__ == "__main__":
    # コマンドライン引数から prefix を取得
    if len(sys.argv) != 2:
        print("Usage: python script.py <prefix>", file=sys.stderr)
        sys.exit(1)

    prefix = sys.argv[1]
    process_lines(prefix)
