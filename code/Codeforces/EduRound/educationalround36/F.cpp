#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,a[N],fa[N],sz[N];
vector<int> g[N];
bool vis[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}


int get(bool mx){
    vector<int> p(n);
    iota(p.begin(),p.end(),1);
    sort(p.begin(),p.end(),[&](int x,int y){
        if(a[x]!=a[y]) return mx?a[x]<a[y]:a[x]>a[y];
        return x<y;
    });

    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,vis[i]=0;
    int res=0;

    for(int i=0;i<n;i++){
        int u=p[i];
        vis[u]=1;
        for(int v:g[u]){
            if(!vis[v]) continue;
            int r=find(v);
            if(r!=u){
                res+=a[u]*sz[u]*sz[r];
                sz[u]+=sz[r];
                fa[r]=u;
            }
        }
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<get(1)-get(0)<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}