#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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

void solve(){
    vector<int> cnt(N);
    int n;
    cin>>n;
    int mx=-N;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
        mx=max(mx,N);
    }
    vector<int> g(mx);

    for(int i=1;i<=mx;i++){
        int s=0;
        for(int j=i;j<=mx;j+=i){
            s+=cnt[j];
        }
        if(s) g[i]=s*qp(2,s-1)%mod; 
    }
    int  res=0;
    for(int i=mx;i>=2;i--){
        for(int j=i*2;j<=mx;j+=i){
            g[i]=(g[i]-g[j]+mod)%mod;
        }
        res=(res+g[i]*i)%mod;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}