import socket
HOST = '127.0.0.1'  # 监听本地环回地址
PORT = 9876         # 监听端口
def start_server():
    print("💻 UDP 服务器启动...")
    # 1. 创建 UDP socket 对象 (socket.SOCK_DGRAM)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # 2. 绑定 IP 地址和端口
        server_socket.bind((HOST, PORT))
        print(f"✅ 监听 {HOST}:{PORT}...")
        
        while True:
            # 3. 接收数据和发送方的地址。UDP 使用 recvfrom() 接收数据和客户端地址。
            data, client_address = server_socket.recvfrom(1024)
            
            message = data.decode('utf-8').strip()
            print(f"[来自 {client_address}] 接收: {message}")
            
            # 检查退出命令
            if message.lower() == 'exit':
                # UDP 是无连接的，服务器无需关闭连接，只需处理完当前数据即可
                print(f"🛑 客户端 {client_address} 请求断开通信。")
                continue # 继续等待下一个客户端或下一条消息
            
            # 构造回显消息
            response = f"Echo: {message}"
            
            # 4. 发送回显消息给客户端。UDP 必须使用 sendto() 并指定目标地址。
            server_socket.sendto(response.encode('utf-8'), client_address)
            
    except KeyboardInterrupt:
        print("\n服务器正在关闭...")
    except Exception as e:
        print(f"发生错误: {e}")
    finally:
        server_socket.close()

if __name__ == "__main__":
    start_server()