#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=1e18;
struct node{
    int u,w;
};

struct st{
    int d,u,mx,mn;
    bool operator>(const st& o) const{
        return d>o.d;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<node>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<vector<vector<int>>> f(n+1,vector<vector<int>>(2,vector<int>(2,inf)));
    priority_queue<st,vector<st>,greater<st>> pq;
    f[1][0][0]=0;
    pq.push({0,1,0,0});
    while(!pq.empty()){
        auto [dis,u,mx,mn]=pq.top();
        pq.pop();
        if(f[u][mx][mn]<dis) continue;
        for(auto& p:g[u]){
            int v=p.u,w=p.w;
            if(f[v][mx][mn]>dis+w){
                f[v][mx][mn]=dis+w;
                pq.push({f[v][mx][mn],v,mx,mn});
            }
            if(mx==0 && f[v][1][mn]>dis){
                f[v][1][mn]=dis;
                pq.push({f[v][1][mn],v,1,mn});
            }
            if(mn==0 && f[v][mx][1]>dis+2*w){
                f[v][mx][1]=dis+2*w;
                pq.push({f[v][mx][1],v,mx,1});
            }
            if(mx==0 && mn==0 && f[v][1][1]>dis+w){
                f[v][1][1]=dis+w;
                pq.push({f[v][1][1],v,1,1});
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<f[i][1][1]<<" ";
    }
    cout<<'\n';
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