#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
const int N=4005;
int fac[N],ifac[N];

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1)res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

int inv(int x){return qp(x,mod-2);}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;    
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
}

int C(int n,int m){
    if(m<0||m>n)return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(k>min(n,m)){
        cout<<0<<'\n';
        return;
    }
    int res=(C(n+m,k)-C(n+m,k-1)+mod)%mod;
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int t;cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}