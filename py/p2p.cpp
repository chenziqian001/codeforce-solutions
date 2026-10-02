#include <iostream>
#include <thread>
#include <string>
#include <cstring>
#include <unistd.h>
#include <winsock2.h>

using namespace std;

void rcv(int fd){
    char buf[1024];
    while(1){
        memset(buf,0,sizeof(buf));
        int n=recv(fd,buf,1024,0);
        if(n<=0) break;
        cout<<"[Peer]: "<<buf<<endl;
    }
}

int main(int argc,char* argv[]){
    if(argc<2) return 1;
    int port=stoi(argv[1]);
    int fd=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);

    if(argc==2){
        addr.sin_addr.s_addr=INADDR_ANY;
        bind(fd,(sockaddr*)&addr,sizeof(addr));
        listen(fd,1);
        int cli=accept(fd,nullptr,nullptr);
        thread t(rcv,cli);
        t.detach();
        string s;
        while(getline(cin,s)){
            send(cli,s.c_str(),s.length(),0);
        }
    }else{
        addr.sin_addr.s_addr=inet_addr(argv[2]);
        connect(fd,(sockaddr*)&addr,sizeof(addr));
        thread t(rcv,fd);
        t.detach();
        string s;
        while(getline(cin,s)){
            send(fd,s.c_str(),s.length(),0);
        }
    }
    return 0;
}