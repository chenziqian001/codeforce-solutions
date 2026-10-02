#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
int fac[N];int ifac[N];

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x) {return qp(x,mod-2);}//逆元

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int res=1;
    int zero=false;
    for(int i=0;i<n-1;i++){
        if(s[i]=='?'){
            if(i!=0)res=res*i%mod;
            else zero=true;
        }
    }
    if(zero){cout<<0<<'\n';}
    else cout<<res<<'\n';

    
    for(int i=0;i<m;i++){
        int pos;
        char c;
        cin>>pos>>c;
        pos--;
        if(s[pos]=='?' && c!='?'){
            if(pos!=0)res=res*inv(pos)%mod;
            else zero=false;
        }
        else if(s[pos]!='?' && c=='?'){
            if(pos!=0) res=res*pos%mod;
            else zero=true;
        }
        s[pos]=c;
        if(zero){
            cout<<0<<'\n';
        }
        else cout<<res<<'\n';
    }
  
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}