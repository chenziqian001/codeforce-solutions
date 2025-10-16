#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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
    int n,m,k;
    cin>>n>>m>>k;
    int sum=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum=(sum+c)%mod;
    }
    int res=2*((k*sum%mod)*inv(n)%mod*inv(n-1)%mod)%mod;
    int d=(n*(n-1)%mod)*inv(2)%mod;
    int id=inv(d);
    int inc=0;
    for(int i=1;i<=k;i++){
        int base=(i*(i-1)%mod)*inv(2)%mod;
        int p=C(k,i)*qp(id,i)%mod*qp(d-1,k-i)%mod*qp(id,k-i)%mod;
        inc=(inc+base*p%mod)%mod;
    }
    inc=(inc*m)%mod;
    res=(res+inc)%mod;
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
