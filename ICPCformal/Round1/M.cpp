#include<bits/stdc++.h>
using namespace  std;
#define int long long
const int N=5100;
int a[N],b[N],t[N],sum;
vector<pair<int,int>> g[N];
pair<int,int> pt[N*2];
void dfs1(int u,int fa){
    t[u]=a[u];
    for(auto nx:g[u]){
        int v=nx.first,w=nx.second;
        if(v==fa) continue;
        dfs1(v,u);
        t[u]=min(t[u],t[v]+w);
    }
}

void dfs2(int u,int fa,int val){
    b[u]=t[u]=min(val,t[u]);
    for(auto nx:g[u]){
        int v=nx.first,w=nx.second;
        if(v==fa) continue;
        dfs2(v,u,b[u]+w);
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        sum+=w;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        pt[i]={u,v};
    }
    fill(a,a+n,sum);
    a[0]=0;
    for(int i=0;i<=n;i++){
        dfs1(0,-1),dfs2(0,-1,sum);
        int tt=0;
        for(int i=0;i<n;i++) tt+=b[i];
        cout<<tt<<'\n';
        for(int i=0;i<n;i++) a[i]=b[i];
        for(int i=0;i<m;i++){
            int u=pt[i].first;
            int v=pt[i].second;
            a[u]=min(a[u],b[v]);
            a[v]=min(a[v],b[u]);
        }
    }
    return 0;
}

