#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int inv(int x) {return qp(x,mod-2);}

void solve(){
    int n,m;
    cin>>n>>m;
    
    int res=(n%mod)*(m%mod)%mod;
    int l=1;
    int u=min(m,n);
    while(l<=u){
        int val=(n/l)%mod;
        int r=min(u,n/(n/l));
        int sum=((l+r)%mod)*((r-l+1)%mod)%mod*inv(2)%mod;
        int add=val*sum%mod;
        res=(res-add+mod)%mod;
        l=r+1;
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}