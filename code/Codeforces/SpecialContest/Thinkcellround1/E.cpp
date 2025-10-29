#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e6+10;
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
    if(n<m || n<0 || m<0) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n;cin>>n;
    for(int k=1;k<=(n-1)/2;k++){
        int res=1;
        for(int base=2*k;base+1<=n;base+=2*k){
            int x=n-base;
            int val=(C(n,x)-C(x+2*k-1,2*k-1)+mod)%mod;
            res=(res+val)%mod;
        }
        cout<<res<<" ";
    }
    cout<<'\n';
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




