#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n);
    int res=0;
    function<void(int,int)> dfs=[&](int node,int fa){
        int deg=g[node].size();
        dp[node]=deg;
        res=max(res,dp[node]);
        for(int next:g[node]){
            if(next==fa) continue;
            dfs(next,node);
            res=max(res,dp[node]+dp[next]-2);
            dp[node]=max(dp[node],dp[next]+deg-2);
        }
    };
    dfs(0,-1);
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}