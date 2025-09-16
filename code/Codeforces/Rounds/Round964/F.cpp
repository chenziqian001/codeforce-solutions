#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=2e5+10;
int fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int C(int n,int m){
    if(m>n) return 0;
    else return fac[n]*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2)%mod;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt+=(x==1);
    }
    int res=0;
    for(int i=k/2+1;i<=min(cnt,k);i++){
        res=(res+C(cnt,i)*C(n-cnt,k-i)%mod)%mod;
    }
    cout<<res<<'\n';
}



signed main(){
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}