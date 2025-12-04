#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> lim(n+2,0);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        lim[r]=max(lim[r],l);
    }

    for(int i=1;i<=n;i++){
        lim[i]=max(lim[i],lim[i-1]);
    }

    vector<int> dp(n+2);
    vector<int> pre(n+3);

    dp[0]=1;
    pre[1]=1;

    for(int i=1;i<=n;i++){
        dp[i]=(pre[i]-pre[lim[i]]+mod)%mod;
        pre[i+1]=(pre[i]+dp[i])%mod;
    }

    int res=dp[n]*2%mod;

    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}