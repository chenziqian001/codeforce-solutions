#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> path;
    vector<int> p(n);
    int md=0;
    int far=0;
    function<void(int,int,int)> dfs=[&](int node,int fa,int dis){
        p[node]=fa;
        if(dis>md){
            md=dis;
            far=node;
        }
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node,dis+1);            
        }
    };

    auto get_path=[&](){
        dfs(0,-1,0);
        int u=far;
        md=0;
        far=0;
        dfs(u,-1,0);
        int v=far;
        while(v!=u){
            path.push_back(v);
            v=p[v];
        }
        path.push_back(u);
    };
    get_path();
    int m=path.size();
    vector<pair<int,int>> ans;
    if(m&1){ 
        int p=path[m/2];
        for(int i=0;i<=m/2;i++){
            ans.emplace_back(p+1,i);
        }
    }
    else{
        int p=path[m/2];
        int q=path[(m-1)/2];
        for(int i=1;i<=m/2;i+=2){
            ans.emplace_back(p+1,i);
            ans.emplace_back(q+1,i);
        }
    }
    cout<<ans.size()<<'\n';

    for(auto [u,d]:ans){
        cout<<u<<" "<<d<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

