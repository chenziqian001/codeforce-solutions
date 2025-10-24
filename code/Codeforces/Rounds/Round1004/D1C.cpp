#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pre[i]=pre[i-1]^x;
    }
    map<int,int> dp;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[pre[i-1]]=(dp[pre[i-1]]*3%mod+dp[pre[i]]*2%mod)%mod;
    }
    int res=0;
    for(auto [_,v]:dp){
        res=(res+v)%mod;
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}