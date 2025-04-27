import sys

if len(sys.argv) < 3:
    print("入力ファイル名と出力ファイル名を指定してください。")
    print("例: python convdef.py input.txt output.txt")
    sys.exit(1)

input_file = sys.argv[1]
output_file = sys.argv[2]

with open(input_file, "r") as f_in, open(output_file, "w") as f_out:
    for line in f_in:
        line = line.strip()
        tokens = line.split()
        symbol = ""
        if len(tokens) >= 3 and tokens[1].strip().lower() == "equ":
            symbol = tokens[0].strip().rstrip(":")
            value = tokens[2].strip()
        elif len(tokens) >= 4 and tokens[0].strip() == "defc" and tokens[2].strip() == "=":
            symbol = tokens[1].strip()
            value = tokens[3].strip()
        if symbol != "":
            line = "#define\t" + symbol + "\t" + value
            f_out.write(line + "\n")