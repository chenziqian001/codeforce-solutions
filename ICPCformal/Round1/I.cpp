#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9;
struct state{
    int node;
    int round;
    int now;

    bool operator<(const state& other) const{
        if(round==other.round) return now>other.now;
        else return round>other.round;
    }

};
int main(){
    int n,m,v,t;
    cin>>n>>m>>v>>t;
    t--;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    pair<int,int> dis[N];
    for(int i=0;i<n;i++) dis[i]={inf,0};
    dis[t]={1,0};
    priority_queue<state> pq;
    pq.push({t,1,0});

    while(!pq.empty()){
        auto qq=pq.top();
        pq.pop();
        int u=qq.node;
        int r=qq.round;
        int used=qq.now;        
        if(make_pair(r,used)>dis[u]) continue;
        for(auto next:g[u]){
            int nu=next.first,w=next.second;
            int nr=r;
            int nused=used;
            if(used+w>v){
                nr=nr+1;
                nused=w;
            }
            else nused+=w;
            if(make_pair(nr,nused)<dis[nu]){
                dis[nu]={nr,nused};
                pq.push({nu,nr,nused});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i].first==inf) cout<<-1<<" ";
        else cout<<dis[i].first<<" ";
    }
    return 0;
}



