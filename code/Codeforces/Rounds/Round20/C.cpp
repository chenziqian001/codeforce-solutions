#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<int> dis(n,-1);
    vector<int> pre(n,-1);

    priority_queue<tuple<int,int,int>> pq;
    pq.emplace(0,0,-1);

    while(!pq.empty()){
        auto [d,node,fa]=pq.top();
        pq.pop();
        
        if(dis[node]!=-1) continue;

        dis[node]=-d;
        pre[node]=fa;

        for(auto [next,w]:g[node]){
            pq.emplace(d-w,next,node);
        }
    }


    if(dis[n-1]==-1){
        cout<<-1<<'\n';
        return 0;
    }
    vector<int> res;
    for(int x=n-1;x!=-1;x=pre[x]){
        res.push_back(x);
    }


    reverse(res.begin(),res.end());
    for(int x:res){
        cout<<x+1<<" ";
    }
    cout<<'\n';
    //system("pause");
    return 0;




}