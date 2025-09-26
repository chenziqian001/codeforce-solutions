#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> pa(n+1);
    vector<vector<int>> t(n+1);
    vector<int> dp(n+1); 
    vector<int> tt(n+1);
    vector<int> d(n+1);
    t[0].push_back(1);
    for(int i=2;i<=n;i++){
        cin>>pa[i];
        d[i]=d[pa[i]]+1;
        t[d[i]].push_back(i);
    }
    dp[1]=tt[0]=1;
    for(int i=1;i<n;i++){
        for(int nx:t[i]){
            dp[nx]=(tt[d[nx]-1]-(d[nx]==1 ? 0:dp[pa[nx]])+mod)%mod;
            tt[d[nx]]=(tt[d[nx]]+dp[nx])%mod;
        }
    }


    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}