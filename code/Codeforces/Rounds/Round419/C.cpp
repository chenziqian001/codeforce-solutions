#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,b;
    cin>>n>>b;
    vector<int> c(n+1),d(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i]>>d[i];
        if(i>1){
            int x;
            cin>>x;
            adj[x].push_back(i);
        }
    }
    vector<vector<array<int,2>>> dp(n+1,vector<array<int,2>>(n+1,{(int)1e18,(int)1e18}));
    vector<int> sz(n+1);

    auto dfs=[&](auto& self,int u)->void{
        sz[u]=1;
        dp[u][0][0]=0;
        dp[u][1][0]=c[u];
        dp[u][1][1]=c[u]-d[u];
        for(int v:adj[u]){
            self(self,v);
            vector<array<int,2>> tmp(sz[u]+sz[v]+1,{(int)1e18,(int)1e18});
            for(int j=0;j<=sz[u];j++){
                for(int k=0;k<=sz[v];k++){
                    tmp[j+k][0]=min(tmp[j+k][0],dp[u][j][0]+dp[v][k][0]);
                    tmp[j+k][1]=min(tmp[j+k][1],dp[u][j][1]+min(dp[v][k][0],dp[v][k][1]));
                }
            }
            sz[u]+=sz[v];
            for(int i=0;i<=sz[u];i++){
                dp[u][i][0]=tmp[i][0];
                dp[u][i][1]=tmp[i][1];
            }
        }
    };
    dfs(dfs,1);
    int res=0;
    for(int i=0;i<=n;i++){
        if(dp[1][i][0]<=b || dp[1][i][1]<=b) res=i;
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
