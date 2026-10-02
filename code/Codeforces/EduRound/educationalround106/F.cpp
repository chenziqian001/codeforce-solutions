#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

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
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    vector<int> d(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        dp[node][0]=1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            vector<int> tmp(k+1);
            int sum=0;
            for(int j=0;j<=d[next];j++){
                sum=(sum+dp[next][j])%mod;
            }
            for(int i=0;i<=d[node];i++){
                tmp[i]=(tmp[i]+dp[node][i]*sum)%mod;
                for(int j=0;j<=d[next];j++){
                    if(i+j+1<=k){
                        int mx=max(i,j+1);
                        tmp[mx]=(tmp[mx]+dp[node][i]*dp[next][j]%mod)%mod;
                    }
                }
            }
            d[node]=max(d[node],d[next]+1);
            d[node]=min(d[node],k);
            for(int i=0;i<=d[node];i++){
                dp[node][i]=tmp[i];
            }
        }
    };

    dfs(1,0);
    int res=0;
    for(int i=0;i<=d[1];i++){
        res=(res+dp[1][i])%mod;
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