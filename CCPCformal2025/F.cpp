#include<bits/stdc++.h>
using namespace std;
int _sg[5000];

long long sg(long long x){
    int t=(x-100)/34;
    t=max(0,t);
    return _sg[x-(t*34)];
}

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
    int n,m;
    cin>>n>>m;
    map<int,unsigned long long> diff;
    diff[n]=0;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        unsigned long long x=rnd();
        diff[l]^=x;
        diff[r]^=x;
    }
    map<unsigned long long,int> lens;
    int last_pos=-1;
    unsigned long long pre=0;
    for(auto &[pos,val]: diff){
        lens[pre]+=pos-last_pos-1;
        pre^=val;
        last_pos=pos;
    }

    int tt=0;
    for(auto [col,len]:lens){
        tt^=sg(len);
    }
    if(tt){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}

int main(){
    _sg[0]=0;
    _sg[1]=0;
    _sg[2]=1;
    _sg[3]=1;
    for(int x=2;x<=200;x++){
        set<int> nextsg;
        for(int i=0;i<=x-2;i++){
            int j=x-i-2;
            nextsg.insert(_sg[i]^_sg[j]);
        }
        int mex=0;
        for(auto s:nextsg){
            if(s==mex){
                mex++;
            }
            else break;
        }
        _sg[x]=mex;
    }

    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}