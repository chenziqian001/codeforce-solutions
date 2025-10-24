#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
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
}//快速幂
int inv(int x){
    return qp(x,mod-2);
}//逆元
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}//初始化阶乘
int C(int n,int m){
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}//组合数


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> cnt(n);
    for(int i=0;i<n;i++) cnt[a[i]]++;

    vector<int> sufc(n+1);
    for(int i=n-1;i>=0;i--){
        sufc[i]=sufc[i+1]+cnt[i];
    }

    vector<int> suf(n,1);
    for(int i=0;i<n;i++){
        suf[i]=qp(2,sufc[i+1]);
    }

    int p=0;
    vector<int> lef=cnt;
    vector<int> f(n);
    int ans=0;
    for(int k=n;k>=1;k--){
        while(p<n && cnt[p]>=k) p++;
        int res=1;
        for(int i=0;i<p;i++){
            while(lef[i]>=k){
                f[i]=(f[i]+C(cnt[i],lef[i]))%mod;
                lef[i]--;
            }
            res=(res*f[i])%mod;
            ans=(ans+res*suf[i]%mod)%mod;
        }
    }
    cout<<ans<<'\n';
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
