#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e6+10;
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


vector<bool> isp(N,true);
void seive(){
    isp[0]=isp[1]=false;
    for(int i=2;i<N;i++){
        if(isp[i]){
            for(int j=i*i;j<N;j+=i) isp[j]=false;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    map<int,int> cnt;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
        cnt[a[i]]+=1;
    }
    vector<int> dp(n+1);
    dp[0]=1;

    for(auto [x,c]:cnt){

        for(int i=n;i>=0;i--){
            if(i<n && isp[x]){
                dp[i+1]=(dp[i+1]+dp[i]*ifac[c-1]%mod)%mod;
            }
            dp[i]=(dp[i]*ifac[c])%mod;
        }
    }

    int res=dp[n]*fac[n]%mod;
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    seive();
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

