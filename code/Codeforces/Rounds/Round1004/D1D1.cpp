#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int N=1e4+10;
int fac[N];
int ifac[N];
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
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}
int C(int n,int m){
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void solve(){
    int n,c,m;
    cin>>n>>c>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    vector<int> dp(m+1);
    vector<int> ndp(m+1);
    dp[c]=1;
    for(int i=2;i<=n;i++){
        for(int i=0;i<=m;i++) ndp[i]=0;
        
        for(int j=0;j<=m;j++){
            int sum=0;
            for(int k=0;k<=c&&k<=j;k++){
                sum=(sum+C(c,k)*dp[j-k]%mod)%mod;
            }    
            ndp[j]=sum;
        }
        for(int i=0;i<=m;i++){
            dp[i]=ndp[i];
        }
    }
    cout<<dp[m]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}