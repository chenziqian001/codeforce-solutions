#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e6+10;
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


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i]; 
    vector<int> prea(n+1);
    vector<int> preb(n+1);
    for(int i=1;i<=n;i++) prea[i]=prea[i-1]+a[i-1];
    for(int i=1;i<=n;i++) preb[i]=preb[i-1]+b[i-1];
    auto get=[](vector<int> &pre,int l,int r){
        return pre[r]-pre[l-1];
    };
    int m=preb[n];
    vector<int> fac(m+1);
    vector<int> ifac(m+1);
    fac[0]=1;
    for(int i=1;i<=m;i++) fac[i]=fac[i-1]*i%mod;
    ifac[m]=inv(fac[m]);
    for(int i=m-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;

    auto C=[&](int n,int m){
        if(n<m || n<0LL || m<0LL) return 0LL;
        return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
    
    };
    
    vector<int> sumC(m+2);
    for(int i=0;i<=m;i++){
        sumC[i+1]=(sumC[i]+C(m,i))%mod;
    }
    int pw2=inv(qp(2,m));
    while(q--){
        int l,r;
        cin>>l>>r;
        int rna=get(prea,l,r);
        int rnb=get(preb,l,r);
        int k=2*rna-prea[n];
        int st=k+rnb;
        int mx=max(0LL,min(m+1,st));
        cout<<sumC[mx]*pw2%mod<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}