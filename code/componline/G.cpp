#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;

void solve(){
    int n,m,C;
    cin>>n>>m>>C;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<vector<int>> adj(n+1),radj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> d1(n+1,1e9),dn(n+1,1e9);
    auto bfs=[&](int st,vector<vector<int>> &g,vector<int> &d){
        queue<int> q;
        q.push(st);
        d[st]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:g[u]){
                if(d[v]>d[u]+1){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
    };
    bfs(1,adj,d1);
    bfs(n,radj,dn);
    if(d1[n]>1e8){
        cout<<0<<'\n';
        return;
    }
    int len=d1[n];
    vector<vector<int>> dag(n+1),rdag(n+1);
    for(int u=1;u<=n;u++){
        for(int v:adj[u]){
            if(d1[u]+1+dn[v]==len){
                dag[u].push_back(v);
                rdag[v].push_back(u);
            }
        }
    }
    int mid=len/2;
    vector<vector<int>> lst(n+1);
    auto dfs1=[&](auto& self,int u,int sum)->void{
        if(d1[u]==mid){
            lst[u].push_back(sum);
            return;
        }
        sum+=c[u];
        if(sum>C) return;
        for(int v:dag[u]) self(self,v,sum);
    };

    dfs1(dfs1,1,0);
    for(int i=1;i<=n;i++) sort(lst[i].begin(),lst[i].end());
    ull res=0;
    auto dfs2=[&](auto& self,int u,int sum)->void{
        sum+=c[u];
        if(sum>C) return;
        if(d1[u]==mid){
            res+=(upper_bound(lst[u].begin(),lst[u].end(),C-sum)-lst[u].begin());
            return;
        }
        for(int v:rdag[u]) self(self,v,sum);
    };

    dfs2(dfs2,n,0);
    cout<<res<<'\n';
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

