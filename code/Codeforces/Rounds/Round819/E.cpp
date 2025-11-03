#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=3e5+10;
int fac[N],ifac[N-1];
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}
void init (){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
    if(n<0 || m<0 || n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]+(i-1)*dp[i-2]%mod)%mod;
    }
    int res=0;
    for(int k=0;4*k<=n;k++){
        int per=fac[2*k]*ifac[k]%mod;
        res=(res+C(n-2*k,2*k)*per%mod*dp[n-4*k]%mod)%mod;
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



