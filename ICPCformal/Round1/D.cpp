#include<bits/stdc++.h>
using namespace  std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> finc(n,-1e18),fdec(n,-1e18),fuse(n);
    auto dfs=[&](auto &&self,int u,int fa)->void{
        vector<int> nx;
        for(int v:t[u]){
            if(v==fa) continue;
            nx.push_back(v);
            self(self,v,u);
        }
        int w=0;
        for(int v:nx) w+=fuse[v];
        for(int v:nx){
            fdec[u]=max(fdec[u],w-fuse[v]+fdec[v]);
            fuse[u]=max(fuse[u],w-fuse[v]+a[u]+fdec[v]);
            finc[u]=max(finc[u],w-fuse[v]+finc[v]);
            fuse[u]=max(fuse[u],w-fuse[v]-a[u]+finc[v]);
        }
        fdec[u]=max(fdec[u],w-a[u]);
        finc[u]=max(finc[u],w+a[u]);
        fuse[u]=max(fuse[u],w);
        int mxinc=-1e18,mxdec=-1e18;
        for(int v:nx){
            mxinc=max(mxinc,finc[v]-fuse[v]);
            mxdec=max(mxdec,fdec[v]-fuse[v]);
        }
        if(mxinc!=-1e18 && mxdec!=-1e18){
            fuse[u]=max(fuse[u],w+mxinc+mxdec);
        }
    };
    dfs(dfs,0,-1);
    cout<<fuse[0]<<'\n';
    return 0;
}
