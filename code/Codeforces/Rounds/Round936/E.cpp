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
int inv(int x) {return qp(x,mod-2);};
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
    if(m>n) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<int> a(m1);
    vector<int> b(m2);
    for(int i=0;i<m1;i++) cin>>a[i];
    for(int i=0;i<m2;i++) cin>>b[i];
    if(a[0]!=1 || b[m2-1]!=n || a[m1-1]!=b[0]){
        cout<<0<<'\n';
        return;
    }

    int res=C(n-1,a[m1-1]-1);
    int cur=a[m1-1]-1;
    for(int i=m1-2;i>=0;i--){
        res=(res*C(cur-1,a[i]-1)%mod*fac[a[i+1]-a[i]-1]%mod)%mod;
        cur=a[i]-1;
    }
    cur=n-1-(a[m1-1]-1);
    for(int i=1;i<m2;i++){
        res=(res*C(cur-1,n-b[i])%mod*fac[b[i]-b[i-1]-1]%mod)%mod;
        cur=n-b[i];
    }
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