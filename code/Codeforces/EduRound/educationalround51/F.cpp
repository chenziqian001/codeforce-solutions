#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1),tr(n+1);
    vector<int> f(n+1);
    for(int i=1;i<=n;i++) f[i]=i;
    auto find=[&](auto self,int x)->int{return f[x]==x?x:f[x]=self(self,f[x]);};

    vector<int> sp;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        int fu=find(find,u),fv=find(find,v);
        if(fu!=fv){
            f[fu]=fv;
            tr[u].push_back({v,w});
            tr[v].push_back({u,w});
        }else{
            sp.push_back(u);
            sp.push_back(v);
        }
    }

    sort(sp.begin(),sp.end());
    sp.erase(unique(sp.begin(),sp.end()),sp.end());
    int k=sp.size();


    vector<vector<int>> d(k,vector<int>(n+1,1e18));


    for(int i=0;i<k;i++){
        int s= sp[i];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        d[i][s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto [cd,u]=pq.top();
            pq.pop();

            if(cd>d[i][u]) continue;
            for(auto [v,w]:g[u]){
                if(d[i][v]>w+cd){
                    d[i][v]=w+cd;
                    pq.push({d[i][v],v});
                }
            }
        }
    }

    vector<int> dep(n+1),td(n+1);
    vector<vector<int>> fa(n+1,vector<int>(20));

    auto dfs=[&](auto self,int u,int p,int dis,int dw)->void{
        dep[u]=dis;
        fa[u][0]=p;
        td[u]=dw;
        for(int i=1;i<20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
        for(auto [v,w]:tr[u]){
            if(v==p)continue;
            self(self,v,u,dis+1,dw+w);
        }
    };
    dfs(dfs,1,0,1,0);

    auto lca=[&](int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        for(int i=19;i>=0;i--){
            if(dep[fa[u][i]]>=dep[v]){
                u=fa[u][i];
            }
            if(u==v) return u;    
        }
        for(int i=19;i>=0;i--){
            if(fa[u][i]!=fa[v][i]){
                u=fa[u][i];v=fa[v][i];
            }
        }
        return fa[u][0];
    };




    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        int res=td[u]+td[v]-2*td[lca(u,v)];
        for(int i=0;i<k;i++){
            res=min(res,d[i][u]+d[i][v]);
        }
        cout<<res<<'\n';
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