#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=6000;
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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1;i<=k;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int p=1;p<=min(i/j,k-j+1);p++){
                dp[i][j]=(dp[i][j]+dp[i-j*p][p])%mod;
            }
        }
    }
    int res=0;
    for(int i=0;i<=n;i++){
        res=(res+dp[n][i])%mod;
    }
    cout<<res<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
