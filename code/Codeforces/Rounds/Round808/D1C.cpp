#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> fa(n+1),in(n+1),out(n+1),dep(n+1),d(n+2);
    vector<vector<int>> adj(n+1),up(n+1,vector<int>(20));
    vector<pair<int,int>> non_mst;
    int timer=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    function<int(int)> find=[&](int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else{
            non_mst.push_back({u,v});
        }
    }
    function<void(int,int)> dfs=[&](int u,int p){
        in[u]=++timer;
        up[u][0]=p;
        for(int i=1;i<20;i++) up[u][i]=up[up[u][i-1]][i-1];
        for(int v:adj[u]){
            if(v!=p){
                dep[v]=dep[u]+1;
                dfs(v,u);
            }
        }
        out[u]=timer;
    };
    dep[1]=1;
    dfs(1,1);

    auto get_lca=[&](int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        for(int i=19;i>=0;i--) if(dep[up[u][i]]>=dep[v])u=up[u][i];
        if(u==v)return u;
        for(int i=19;i>=0;i--) if(up[u][i]!=up[v][i])u=up[u][i],v=up[v][i];
        return up[u][0];
    };

    auto get_child=[&](int u,int anc){
        for(int i=19;i>=0;i--) if(dep[u]-(1<<i)>dep[anc])u=up[u][i];
        return u;
    };

    auto update=[&](int l,int r,int val){
        if(l>r)return;
        d[l]+=val;
        d[r+1]-=val;
    };

    for(auto e:non_mst){
        int u=e.first,v=e.second;
        int lca=get_lca(u,v);

        if(lca!=u && lca!=v){
            update(1,n,1); 
            update(in[u],out[u],-1);
            update(in[v],out[v],-1);
        }else{
            if(lca==v) swap(u,v);
            int ch=get_child(v,u);
            update(in[ch],out[ch],1);
            update(in[v],out[v],-1); 
        }
    }
    for(int i=1;i<=n;i++) d[i]+=d[i-1];
    for(int i=1;i<=n;i++){
        if(!d[in[i]]) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
    //system("pause");
    return 0;
}