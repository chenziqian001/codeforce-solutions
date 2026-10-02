#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> sz(n+1);
    vector<int> dp(n+1);
    vector<int> max1(n+1),max2(n+1),max_son(n+1);
    
    auto dfs1=[&](auto& self,int u,int p)->void{
        sz[u]=1;
        for(int v:adj[u]){
            if(v==p) continue;
            self(self,v,u);
            sz[u]+=sz[v];
            
            int cur_max=dp[v];
            if(cur_max>max1[u]){
                max2[u]=max1[u];
                max1[u]=cur_max;
                max_son[u]=v;
            }else if(cur_max>max2[u]){
                max2[u]=cur_max;
            }
        }
        if(sz[u]<=n/2) dp[u]=sz[u];
        else dp[u]=max1[u];
    };
    vector<int> up(n+1,0);
    auto dfs2=[&](auto& self,int u,int p)->void{
        for(int v:adj[u]){
            if(v==p) continue;
            int up_sz=n-sz[v];
            if(up_sz<=n/2){
                up[v]=up_sz;
            }else{
              
                int val=up[u]; 
                if(max_son[u]==v) val=max(val,max2[u]);
                else val=max(val,max1[u]);
                
                up[v]=val;
            }
            self(self,v,u);
        }
    };
    
    dfs1(dfs1,1,0);
    dfs2(dfs2,1,0);
    
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        int big_cnt=0,fail_size=0,cut_max=0;

        if(n-sz[i]>n/2){
            big_cnt++;
            fail_size=n-sz[i];
            cut_max=up[i];
        }

        for(int v:adj[i]){
            if(sz[v]>sz[i]) continue;
            if(sz[v]>n/2){
                big_cnt++;
                fail_size=sz[v];
                cut_max=dp[v];
            }
        }
        
        if(big_cnt==0){
            ans[i]=1;
        }else if(big_cnt>1){
            ans[i]=0;
        }else{
            if(fail_size-cut_max<=n/2) ans[i]=1;
            else ans[i]=0;
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" \n"[i==n];
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}