#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
vector<int> t[N];
int sz[N],dep[N],son[N],top[N],bot[N],fa[N];
vector<int> chain[N];

void dfs1(int u,int f){
    sz[u]=1,fa[u]=f;
    for(int v:t[u]){
        if(v==f) continue;
        dep[v]=dep[u]+1;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int tp){
    top[u]=tp;
    chain[tp].push_back(u);
    if(son[u]) dfs2(son[u],tp);
    bot[u]=son[u]?bot[son[u]]:u;
    for(int v:t[u]){
        if(v!=fa[u] && v!=son[u]) dfs2(v,v);
    }

}




void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    cout<<"d 1"<<endl;
    int dx;
    cin>>dx;
    int u=1;
    while(1){
        int b=bot[u];
        cout<<"d "<<b<<endl;
        int db;
        cin>>db;
        int dlca=(dep[b]+dx-db)/2;
        int lca=chain[top[u]][dlca-dep[top[u]]];
        if(dlca==dx){
            cout<<"! "<<lca<<endl;
            return;
        }
        cout<<"s "<<lca<<endl;
        cin>>u;
    }
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