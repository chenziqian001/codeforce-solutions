# tcp_client.py
import socket
HOST = '127.0.0.1'  # 服务器地址
PORT = 6789         # 服务器端口
def start_client():
    """启动 TCP 客户端"""
    # 1. 创建 socket 对象
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        # 2. 连接服务器
        client_socket.connect((HOST, PORT))
        print(f"✅ 成功连接到服务器 {HOST}:{PORT}")
        print("💡 输入消息，输入 'exit' 结束程序。")
        
        while True:
            # 3. 获取用户输入
            message = input(">>> ")
            
            # 4. 检查退出命令
            if message.lower() == 'exit':
                print("程序结束。")
                # 向服务器发送退出命令
                client_socket.sendall(message.encode('utf-8'))
                break

            # 5. 发送消息（编码为字节）
            client_socket.sendall(message.encode('utf-8'))
            
            # 6. 接收服务器的回显（解码为字符串）
            response = client_socket.recv(1024).decode('utf-8')
            print(f"[服务器回显] {response}")
    except ConnectionRefusedError:
        print("❌ 错误：连接被拒绝。请确保服务器程序正在运行。")
    except ConnectionResetError:
        print("❌ 错误：服务器已断开连接。")
    except Exception as e:
        print(f"❌ 发生错误: {e}")
    finally:
        # 7. 关闭 socket
        client_socket.close()
if __name__ == "__main__":
    start_client()