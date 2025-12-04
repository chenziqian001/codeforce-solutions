import socket
HOST = '127.0.0.1'  # 服务器地址
PORT = 9876         # 服务器端口
SERVER_ADDRESS = (HOST, PORT)
def start_client():
    # 1. 创建 UDP socket 对象 (socket.SOCK_DGRAM)
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f"✅ UDP 客户端启动，将发送到 {HOST}:{PORT}")
    print("💡 输入消息，输入 'exit' 结束程序。")
    try:
        while True:
            message = input(">>> ")
            # 2. 检查退出命令
            if message.lower() == 'exit':
                # UDP 无需关闭连接，发送 'exit' 告知服务器
                client_socket.sendto(message.encode('utf-8'), SERVER_ADDRESS)
                print("程序结束。")
                break
            
            # 3. 发送消息。UDP 使用 sendto() 且必须指定目标地址。
            client_socket.sendto(message.encode('utf-8'), SERVER_ADDRESS)
            
            # 4. 接收服务器的回显和地址。UDP 使用 recvfrom() 接收数据和服务器地址。
            print("等待服务器回显...")
            data, server = client_socket.recvfrom(1024)
            
            response = data.decode('utf-8')
            print(f"[服务器回显] {response}")
            
    except Exception as e:
        print(f"❌ 发生错误: {e}")
    finally:
        # 5. 关闭 socket
        client_socket.close()

if __name__ == "__main__":
    start_client()