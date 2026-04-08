#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
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
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;    
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}//初始化阶乘
int C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}//组合数

void solve(){
    int n;
    cin>>n;
    vector<int> deg(n);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        deg[u]++;
        deg[v]++;
    }


    int res=1;
    for(int i=0;i<n;i++){
        res=res*fac[deg[i]]%mod;
    }
    res=res*n%mod;
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
