#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int N=500;
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int x=(i+j)%2==0?1:-1;
            int val=x*C(n,j)%mod;
            val=val*C(n,i)%mod;
            val=val*qp(k-1,n*(i+j)-i*j)%mod;
            val=val*qp(k,n*n-n*(i+j)+i*j)%mod;
            res=(res+val+mod)%mod;
        }
    }
    cout<<res<<'\n';
}


