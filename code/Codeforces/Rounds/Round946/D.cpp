#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c[4]={0};
    for(char x:s){
        if(x=='N')c[0]++;
        else if(x=='S')c[1]++;
        else if(x=='E')c[2]++;
        else c[3]++;
    }
    if(abs(c[0]-c[1])%2!=0||abs(c[2]-c[3])%2!=0){
        cout<<"NO"<<'\n';
        return;
    }
    string p="";
    int t[4]={0,0,1,1};
    for(char x:s){
        if(x=='N'){p+=(t[0]==0?'R':'H');t[0]^=1;}
        else if(x=='S'){p+=(t[1]==0?'R':'H');t[1]^=1;}
        else if(x=='E'){p+=(t[2]==0?'R':'H');t[2]^=1;}
        else{p+=(t[3]==0?'R':'H');t[3]^=1;}
    }
    int r=0,h=0;
    for(char x:p){
        if(x=='R')r++;
        else h++;
    }
    if(r==0||h==0)cout<<"NO"<<'\n';
    else cout<<p<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}