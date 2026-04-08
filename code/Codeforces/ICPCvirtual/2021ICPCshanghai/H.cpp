#include<bits/stdc++.h>
using namespace std;
#define int long long

struct E{
    int u,v,w;
    bool operator<(const E& o)const{return w<o.w;}
};

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n*2,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    
    vector<E> e(m);
    for(int i=0;i<m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e.begin(),e.end());
    
    vector<int> dsu(n*2);
    for(int i=1;i<n*2;i++)dsu[i]=i;

    auto f=[&](auto& f,int x)->int{return x==dsu[x]?x:dsu[x]=f(f,dsu[x]);};
    
    int tot=n;
    vector<int> val(n*2,0),sum(n*2,0),lc(n*2,0),rc(n*2,0);
    vector<vector<int>> fa(n*2,vector<int>(20,0)),mk(n*2,vector<int>(20,0));
    
    for(int i=0;i<m;i++){
        int u=f(f,e[i].u),v=f(f,e[i].v);
        if(u!=v){
            tot++;
            dsu[u]=dsu[v]=tot;
            val[tot]=e[i].w;
            lc[tot]=u;rc[tot]=v;
            fa[u][0]=tot;
            fa[v][0]=tot;
        }
    }
    
    for(int i=1;i<=n;i++)sum[i]=a[i];
    for(int i=n+1;i<=tot;i++)sum[i]=sum[lc[i]]+sum[rc[i]];
    
    for(int u=tot;u>=1;u--){
        if(fa[u][0])mk[u][0]=max(0LL,val[fa[u][0]]-sum[u]);
        for(int i=1;i<20;i++){
            fa[u][i]=fa[fa[u][i-1]][i-1];
            mk[u][i]=max(mk[u][i-1],mk[fa[u][i-1]][i-1]);
        }
    }
    
    while(q--){
        int x,k;
        cin>>x>>k;
        for(int i=19;i>=0;i--){
            if(fa[x][i]&&k>=mk[x][i])x=fa[x][i];
        }
        cout<<k+sum[x]<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}