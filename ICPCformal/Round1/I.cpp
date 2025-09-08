#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=1e18;

signed main(){
    int n,m,V,T;
    cin>>n>>m>>V>>T;
    T--; 
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    vector<int> dis(n,inf);
    dis[T] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    vector<bool> vis(n,false);
    pq.emplace(0,T);

    while(!pq.empty()){
        auto pa = pq.top();
        int x = pa.second;
        pq.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto npa : g[x]){
            int y = npa.first;
            long long w = npa.second; 
            if(dis[x] + w < dis[y]){
                dis[y] = dis[x] + w;
                pq.emplace(dis[y], y);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dis[i] == inf){
            cout<<-1<<" ";
            continue;
        }
        if(V == 0){
            cout<<-1<<" ";
            continue;
        }
        if(dis[i] % V == 0){
            dis[i] = dis[i] / V;
            if(dis[i] < 1) dis[i] = 1;
        } else {
            dis[i] = (dis[i] / V) + 1;
        }
        cout<<dis[i]<<" ";
    }
    return 0;
}
