import socket

# サーバーのホストとポートを定義
HOST = '0.0.0.0'
PORT = 3000        # 任意のポート番号

# ソケットを作成
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))  # サーバーを指定したホストとポートにバインド
    s.listen()  # 接続要求を待つ
    print(f'Server is listening on {HOST}:{PORT}')
    
    while True:
        conn, addr = s.accept()  # 接続要求を受け入れ、クライアントのソケットとアドレスを取得
        with conn:
            print(f'Connected by {addr}')
            while True:
                data = conn.recv(1024)  # クライアントからデータを受信
                if not data:
                    print(f'Disconnect {addr}')
                    break  # データがなければ接続を終了
                conn.sendall(data)  # 受信したデータをそのままクライアントに送信
                print(f'Echoed: {data.decode()}')  # データを表示
