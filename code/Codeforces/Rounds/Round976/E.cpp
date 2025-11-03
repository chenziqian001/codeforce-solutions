#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> dp(1<<10,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        vector<int> ndp(1<<10,0);
        for(int j=0;j<(1<<10);j++){
            ndp[j^a[i]]=(ndp[j^a[i]]+dp[j]*p[i]%mod)%mod;
            ndp[j]=(ndp[j]+dp[j]*(10000-p[i])%mod)%mod;
        }
        dp=ndp;
    }
    int res=0;
    for(int i=0;i<(1<<10);i++){
        res=(res+dp[i]*i%mod*i%mod)%mod;
    }
    cout<<res*inv(qp(10000,n))%mod<<'\n';
} 



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}