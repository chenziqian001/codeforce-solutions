#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            if(i>1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            if(i<n) dp[i][j]=(dp[i][j]+dp[i+1][j-1])%mod;
        }
    }
    vector<vector<int>> com(n+1,vector<int>(k+1));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            com[i][j]=dp[i][j]*dp[i][k-j]%mod;
        }
    }


    int res=0;
    vector<int> t(n+1);
    for(int i=1;i<=n;i++){
        int tt=0;
        for(int j=0;j<=k;j++){
            tt=(tt+com[i][j])%mod;
        }
        t[i]=tt;
        res=(res+a[i]*tt%mod)%mod;
    }

    while(q--){
        int pos,val;
        cin>>pos>>val;
        res=(res-a[pos]*t[pos]%mod+mod)%mod;
        a[pos]=val;
        res=(res+a[pos]*t[pos]%mod)%mod;
        cout<<res<<'\n';
    }
    //system("pause");
}