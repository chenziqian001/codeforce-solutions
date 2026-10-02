#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
long long n,fac[N],ifac[N],mul[N],sz[N],f[N],dp[N][N];
vector<vector<long long>> tr;
long long qpow(long long a,long long n){
    long long res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
long long inv(long long a){
    return qpow(a,mod-2);
}
void init(){
    fac[0]=1LL;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[n]=inv(fac[n]);
    for(int i=n-1;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}
long long C(long long n,long long m){
    if(n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void dfs1(int u){
    sz[u]=mul[u]=f[u]=1LL;
    for(int v:tr[u]){
        dfs1(v);
        sz[u]=(sz[u]+sz[v])%mod;
        mul[u]=mul[u]*mul[v]%mod;
    }
    mul[u]=mul[u]*sz[u]%mod;
    f[u]=fac[sz[u]]*inv(mul[u])%mod;
}
void dfs2(int u){
    for(int v:tr[u]){
        long long cuv=C(sz[u]-1,sz[v]);
        long long tmp=f[u]*inv(cuv)%mod*inv(f[v])%mod;
        for(int i=1;i<=n;i++){
            dp[v][i]=dp[u][i-1]*tmp%mod*C(n-i+1-sz[v],sz[u]-sz[v]-1)%mod;
            dp[v][i]+=dp[v][i-1];
            dp[v][i]%=mod;
        }
        dfs2(v);
    }
}
void solve(){
    cin>>n;
    init();
    tr.resize(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tr[x].push_back(i);
    }
    dp[1][1]=1LL;
    dfs1(1LL);
    dfs2(1LL);
    for(int i=1;i<=n;i++){
        dp[i][i]=dp[i][i]*f[i]%mod*C(n-i,sz[i]-1)%mod;
        cout<<dp[i][i]%mod<<" ";
    }
    cout<<'\n';
}


signed main(){
    solve();
    system("pause");
    return 0;
}