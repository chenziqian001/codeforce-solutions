#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod;
const int N=5010;
int fac[N];int ifac[N];
//插板法，每人至少分到1,C(n-1,m-1),允许为空:C(n+m-1,m-1);
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
    cin>>n>>mod;    
    init();
    vector<vector<int>> dp(n+5,vector<int>(n+5));
    for(int i=1;i<=n;i++) dp[i][i]=qp(2,i-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(!dp[i][j]) continue;
            for(int len=1;len+i+1<=n;len++){
                dp[i+1+len][j+len]=(dp[i+1+len][j+len]+dp[i][j]*qp(2,len-1)%mod*C(j+len,len)%mod)%mod;
            }
        }
    }
    int res=0;
    for(int j=1;j<=n;j++) res=(res+dp[n][j])%mod;
    cout<<res<<'\n';
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