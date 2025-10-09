#include<bits/stdc++.h>
using namespace std;
int n,m;

int find(vector<int> &pa,int x){
    if(x!=pa[x]) pa[x]=find(pa,pa[x]);
    return pa[x];
}
void merge(vector<int> &pa,int x,int y){
    int px=find(pa,x);
    int py=find(pa,y);
    if(px==py) return;
    pa[py]=px;
    return;
}
void solve(){
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<pair<int,int>> e(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e[i]={u,v};
    }
    vector<int> fa(n,-1);
    vector<int> d(n);
    vector<int> vis(n,false);
    function<void(int)> dfs=[&](int node){
        vis[node]=true;
        for(int next:g[node]){
            if(vis[next]) continue;
            fa[next]=node;
            d[next]=d[node]+1;
            dfs(next);
        }
        
    };
    dfs(0);
    vector<int> pa(n);
    iota(pa.begin(),pa.end(),0);
    for(auto &[u,v]:e){
        if(fa[u]!=v) swap(u,v);
        if(fa[u]!=v){
            int x=u,y=v;
            while(true){
                x=find(pa,x),y=find(pa,y);
                if(x==y) break;
                if(d[x]>d[y]){
                    merge(pa,fa[x],x);
                }
                else merge(pa,fa[y],y);
            }
        }
    }
   
    vector<int> must(n,0);
    for(int i=n-1;i>0;i=fa[i]){
        if(find(pa,i)==i) must[i]=1;
    }
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        auto [u,v]=e[i];
        if(fa[u]==v && must[u]){
            q.emplace(u,i+1);
            q.emplace(v,i+1);
        }
    }
    vector<int> dp(n,-1);
    while(!q.empty()){
        auto [node,id]=q.front();
        q.pop();
        if(dp[node]!=-1) continue;
        dp[node]=id;
        for(int next:g[node]){
            q.emplace(next,id);
        }
    }
    int ask;
    cin>>ask;
    bool ok=true;
    for(int i=0;i<ask;i++){
        int pos;
        cin>>pos;
        pos--;
        cout<<dp[pos]<<" "; 
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}