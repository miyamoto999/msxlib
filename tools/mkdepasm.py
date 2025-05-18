import os
import glob
import re
import sys

include_dirs = [ "./"]
asm_files = []

args = sys.argv[1:]
for arg in args:
    if arg.startswith('-I'):
        include_dirs.append(arg[2:])  # -I後のディレクトリをリストに追加
    elif arg.startswith('-'):
        continue
    else:
        asm_files.append(arg)  # ファイルをリストに追加

def find_header(header, current_dir):
    search_dirs = [current_dir] + include_dirs
    for dir in search_dirs:
        candidate = os.path.join(dir, header)
        if os.path.isfile(candidate):
            return os.path.normpath(candidate)
    return None

def remove_comments(source_code):
    # 複数行コメント削除（Cスタイル）
    source_code = re.sub(r'/\*.*?\*/', '', source_code, flags=re.DOTALL)
    # 行末コメント削除：C++スタイル
    source_code = re.sub(r'//.*', '', source_code)
    # 行末コメント削除：アセンブリスタイル
    source_code = re.sub(r';.*', '', source_code)
    return source_code

def parse_dependencies(start_file):
    deps = set()
    to_process = [start_file]
    seen = set()

    while to_process:
        current = to_process.pop()
        if current in seen:
            continue
        seen.add(current)
        current_dir = os.path.dirname(current) or '.'

        try:
            with open(current, 'r', encoding='utf-8', errors='ignore') as f:
                source = f.read()
                source = remove_comments(source)
                lines = source.splitlines()

                for line in lines:
                    match = re.match(r'\s*include\s+"([^"]+)"', line, re.IGNORECASE)
                    if match:
                        header_name = match.group(1)
                        full_path = find_header(header_name, current_dir)
                        if full_path and full_path not in seen:
                            deps.add(full_path)
                            to_process.append(full_path)
        except FileNotFoundError:
            continue  # 存在しないファイルは無視

    return deps

# 出力：Makefile形式
for c_file in asm_files:
    deps = parse_dependencies(c_file)
    obj_file = os.path.splitext(c_file)[0] + '.o'
    dep_files = ' '.join(deps)
    print(f'{obj_file}: {c_file} {dep_files}')
