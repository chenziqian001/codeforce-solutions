#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
vector<int> e[N];
int f[N][21],d[N];
void dfs(int u,int p){
    d[u]=d[p]+1;
    f[u][0]=p;
    for(int i=1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
    for(int v:e[u])if(v!=p)dfs(v,u);
}
int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    for(int i=20;i>=0;i--)if(d[f[u][i]]>=d[v])u=f[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;i--)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
    return f[u][0];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,s;cin>>n>>m>>s;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(s,0);
    while(m--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
    return 0;
}