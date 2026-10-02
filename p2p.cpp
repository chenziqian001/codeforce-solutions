#include <iostream>
#include <thread>
#include <string>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

// 接收线程函数：专门负责死循环收消息并打印
void rcv_loop(SOCKET fd) {
    char buf[1024];
    while(true) {
        memset(buf, 0, sizeof(buf));
        int n = recv(fd, buf, 1024, 0);
        if(n <= 0) {
            cout << "\n[Connection closed by peer]" << endl;
            break;
        }
        cout << "\r[Peer]: " << buf << "\n> " << flush;
    }
}

int main(int argc, char* argv[]) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    if(argc < 2) {
        cout << "Usage: p2p <port> [ip]" << endl;
        return 1;
    }
    
    int port = stoi(argv[1]);
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    SOCKET comm_fd;
    if(argc == 2) {
        addr.sin_addr.s_addr = INADDR_ANY;
        bind(fd, (sockaddr*)&addr, sizeof(addr));
        listen(fd, 1);
        cout << "Waiting for connection on port " << port << "..." << endl;
        comm_fd = accept(fd, nullptr, nullptr);
        cout << "Connected!" << endl;
    } else {
        addr.sin_addr.s_addr = inet_addr(argv[2]);
        cout << "Connecting to " << argv[2] << ":" << port << "..." << endl;
        connect(fd, (sockaddr*)&addr, sizeof(addr));
        comm_fd = fd;
        cout << "Connected!" << endl;
    }

    // 启动独立线程专门收消息
    thread t(rcv_loop, comm_fd);
    t.detach();

    // 主线程专门负责发消息
    string s;
    cout << "> " << flush;
    while(getline(cin, s)) {
        if(s.empty()) continue;
        send(comm_fd, s.c_str(), s.length(), 0);
        cout << "> " << flush;
    }

    closesocket(comm_fd);
    closesocket(fd);
    WSACleanup();
    return 0;
}