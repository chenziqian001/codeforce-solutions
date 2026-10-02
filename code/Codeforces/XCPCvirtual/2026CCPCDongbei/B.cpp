#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});g[v].push_back({u,w});
    }

    vector<int>dep(n+1),dis(n+1);
    vector<vector<int>>up(n+1,vector<int>(20)),f(n+1,vector<int>(20));

    vector<int>d1(n+1),d2(n+1),d3(n+1),s1(n+1),s2(n+1),s3(n+1),uval(n+1);

    auto dfs1=[&](auto&&self,int u,int p,int d)->void{
        dep[u]=dep[p]+1;dis[u]=d;up[u][0]=p;
        for(int k=1;k<20;k++)up[u][k]=up[up[u][k-1]][k-1];
        for(auto x:g[u]){
            int v=x.first,w=x.second;
            if(v==p)continue;
            self(self,v,u,d+w);
            int val=d1[v]+w;
            if(val>d1[u]){
                d3[u]=d2[u];s3[u]=s2[u];
                d2[u]=d1[u];s2[u]=s1[u];
                d1[u]=val;s1[u]=v;
            }else if(val>d2[u]){
                d3[u]=d2[u];s3[u]=s2[u];
                d2[u]=val;s2[u]=v;
            }else if(val>d3[u]){
                d3[u]=val;s3[u]=v;
            }
        }
    };

    auto dfs2=[&](auto&&self,int u,int p,int uv)->void{
        uval[u]=uv;
        for(auto x:g[u]){
            int v=x.first,w=x.second;
            if(v==p)continue;
            int sib=(s1[u]==v)?d2[u]:d1[u]; 
            self(self,v,u,max(0LL,w+max(uv,sib)));
        }
    };

    dfs1(dfs1,1,0,0);
    dfs2(dfs2,1,0,0);
    for(int i=2;i<=n;i++)f[i][0]=(s1[up[i][0]]==i)?d2[up[i][0]]:d1[up[i][0]];
    for(int k=1;k<20;k++)for(int i=1;i<=n;i++)f[i][k]=max(f[i][k-1],f[up[i][k-1]][k-1]);
    

    auto lca=[&](int u,int v){
        if(dep[u]<dep[v])swap(u,v);
        for(int k=19;k>=0;k--)if(dep[up[u][k]]>=dep[v])u=up[u][k];
        if(u==v)return u;
        for(int k=19;k>=0;k--)if(up[u][k]!=up[v][k]){u=up[u][k];v=up[v][k];}
        return up[u][0];
    };


    auto get_s=[&](int u,int anc){
        for(int k=19;k>=0;k--)if(dep[up[u][k]]>dep[anc])u=up[u][k];
        return u;
    };

    auto q_path=[&](int u,int diff){
        int res=0;
        for(int k=19;k>=0;k--)if((diff>>k)&1){res=max(res,f[u][k]);u=up[u][k];}
        return res;
    };


    while(q--){
        int x,y;cin>>x>>y;
        if(x==y){cout<<2*max(d1[x],uval[x])<<"\n";continue;} 
        int L=lca(x,y);
        int D=dis[x]+dis[y]-2*dis[L];
        int mx=0,sx=0,sy=0;
        if(x!=L){
            sx=get_s(x,L);
            int diff=dep[x]-dep[L]-1;
            if(diff>0)mx=max(mx,q_path(x,diff));
            mx=max(mx,d1[x]);
        }
        if(y!=L){
            sy=get_s(y,L);
            int diff=dep[y]-dep[L]-1;
            if(diff>0)mx=max(mx,q_path(y,diff));
            mx=max(mx,d1[y]);
        }
        int vL=uval[L];
        if(s1[L]!=sx&&s1[L]!=sy)vL=max(vL,d1[L]);
        else if(s2[L]!=sx&&s2[L]!=sy)vL=max(vL,d2[L]);
        else vL=max(vL,d3[L]);
        mx=max(mx,vL);
        
        cout<<D+2*mx<<"\n";
    }
    return 0;
}