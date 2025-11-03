#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1000;
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
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=' '+s;
    vector<vector<int>> dp(n+2,vector<int>(k+1));
    dp[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=k;j++){
            int mx=j/2+(s[i]=='0' && j&1);
            for(int x=0;x<=mx;x++){
                dp[i][j]=(dp[i][j]+dp[i+1][j-x]*C(mx,x)%mod)%mod;
            }
        }
    }
    cout<<dp[1][k]<<'\n';

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