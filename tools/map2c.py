# -*- coding: utf-8 -*-
import sys

if len(sys.argv) < 3:
    print("入力ファイル名と出力ファイル名を指定してください。")
    print("例: python map2c.py input.txt output.txt")
    sys.exit(1)

input_file = sys.argv[1]
output_file = sys.argv[2]

with open(input_file, "r") as f_in, open(output_file, "w") as f_out:
    for line in f_in:
        line = line.strip()
        tokens = line.split()
        if len(tokens) >= 3 and tokens[1] == "=":
            symbol = tokens[0].strip()
            value = tokens[2].strip(";")
            line = "#define ADDR_" + symbol + "\t" + value.replace("$", "0x")
            f_out.write(line + "\n")
