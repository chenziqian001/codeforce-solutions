import socket
import threading
HOST = '127.0.0.1'  # 监听本地环回地址
PORT = 6789         # 监听端口
def handle_client(conn, addr):
    """处理单个客户端连接的函数"""
    print(f"✅ 客户端 {addr} 已连接.")
    try:
        while True:
            # 接收数据，缓冲区大小为 1024 字节
            data = conn.recv(1024)
            if not data:
                # 客户端关闭了连接
                break
            
            # 将接收到的字节数据解码为字符串
            message = data.decode('utf-8').strip()
            print(f"[来自 {addr}] 接收: {message}")
            
            # 检查退出命令
            if message.lower() == 'exit':
                print(f"🛑 客户端 {addr} 请求断开连接.")
                break

            # 构造回显消息 (Echo)
            response = f"Echo: {message}"
            
            # 将字符串编码为字节并发送回客户端
            conn.sendall(response.encode('utf-8'))
            
    except ConnectionResetError:
        print(f"❌ 客户端 {addr} 意外断开连接.")
    finally:
        # 关闭连接
        conn.close()
        print(f"❌ 连接已关闭: {addr}")

def start_server():
    """启动 TCP 服务器"""
    # 1. 创建 socket 对象
    # socket.AF_INET 表示使用 IPv4 地址族
    # socket.SOCK_STREAM 表示使用 TCP 协议
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 允许重复使用地址，防止程序关闭后端口立即被占用
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    # 2. 绑定 IP 地址和端口
    server_socket.bind((HOST, PORT))
    # 3. 开始监听，最多允许 5 个未接受的连接排队
    server_socket.listen(5)
    print(f"💻 TCP 服务器启动，监听 {HOST}:{PORT}...")
    try:
        while True:
            # 4. 阻塞等待客户端连接
            conn, addr = server_socket.accept()
            
            # 5. 为每个连接启动一个新线程处理，实现并发
            client_thread = threading.Thread(target=handle_client, args=(conn, addr))
            client_thread.start()
    except KeyboardInterrupt:
        print("\n服务器正在关闭...")
    finally:
        server_socket.close()
if __name__ == "__main__":
    start_server()