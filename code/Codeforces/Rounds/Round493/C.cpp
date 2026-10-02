#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1000001;
int fac[N];int ifac[N];

int qp(int a,int n){
    int res=1;
    a%=mod;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

int inv(int x){return qp(x,mod-2);}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

int C(int n,int m){return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin>>n;

    int c1=0,c2=0;

    for(int i=1;i<=n;i++){
        int si=(i&1)?1:-1;
        int com=(C(n,i)*si+mod)%mod;

        int row=qp(3,i+n*(n-i));
        c1=(c1+row*com)%mod;

        int x=qp(3,n-i);
        int p1=qp((x-1+mod)%mod,n);
        int p2=qp(3,n*(n-i));
        int p3=(p1-p2+mod)%mod;
        c2=(c2+com*p3)%mod;
    }

    c1=c1*2%mod;
    c2=c2*3%mod;
    int res=(c1+c2)%mod;
    cout<<res<<'\n';
    return 0;
}