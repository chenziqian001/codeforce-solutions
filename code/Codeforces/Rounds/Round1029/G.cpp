#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }

    auto dij=[&](int node)->vector<int>{
        vector<int> dis(n,inf);
        vector<int> vis(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node});
        while(pq.size()){
            auto [w,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            dis[u]=w;

            for(auto [nw,v]:g[u]){
                if(vis[v]) continue;
                pq.push({max(nw,w),v});
            }
        }
        return dis;
    };
    int res=inf;
    vector<int> dis_s=dij(0);
    vector<int> dis_t=dij(n-1);

    for(int u=0;u<n;u++){
        for(auto [w,v]:g[u]){
            res=min(res,max({dis_s[u],dis_t[v],w})+w);
        }
    }

    cout<<res<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}