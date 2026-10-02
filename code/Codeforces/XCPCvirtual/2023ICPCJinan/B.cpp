#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<vector<pair<int,int>>> dp(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        dp[node].push_back({1,1});
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            int sum=0;
            for(auto pn:dp[next]){
                if(pn.first==k || pn.first==k+1) sum+=pn.second;
            }
            vector<pair<int,int>> ndp;
            for(auto pn:dp[node]){
                if(sum) ndp.push_back({pn.first,pn.second*sum%mod});
                for(auto pnn:dp[next]){
                    if(pn.first+pnn.first<=k+1){
                        ndp.push_back({pn.first+pnn.first,pn.second*pnn.second%mod});
                    }
                }
            }
            sort(ndp.begin(),ndp.end());
            dp[node].clear();
            for(auto pn:ndp){
                if(dp[node].empty() || dp[node].back().first!=pn.first){
                    dp[node].push_back(pn);
                }
                else dp[node].back().second=(dp[node].back().second+pn.second)%mod;
            }
        }
    };
    dfs(1,0);
    int res=0;
    for(auto p:dp[1]){
        if(p.first==k || p.first==k+1){
            res=(res+p.second)%mod;
        }
    }
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


