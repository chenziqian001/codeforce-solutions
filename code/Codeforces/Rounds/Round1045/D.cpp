#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    int mx=0;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;      
        mx=max(mx,deg[u]);
        mx=max(mx,deg[v]);
    }
    if(mx<=2){
        cout<<-1<<'\n';
        return;
    }

    vector<int> p(n);
    function<pair<int,int>(int,int,int)> dfs=[&](int node,int fa,int dis)->pair<int,int>{
        p[node]=fa;
        int pos=node;
        int mxd=dis;
        for(int next:g[node]){
            if(next==fa) continue;
            auto [nf,nd]=dfs(next,node,dis+1);
            if(nd>mxd){
                pos=nf;
                mxd=nd;
            }
        }
        return {pos,mxd};
    };
    vector<int> path;
    int u=dfs(0,-1,0).first;
    int v=dfs(u,-1,0).first;
    while(p[v]!=-1){
        path.push_back(v);
        v=p[v];
    }
    p.push_back(u);
  

    
    int m=path.size();
    for(int i=0;i<m;i++){
        int x=path[i];
        if(deg[x]>=3){
            int pre=path[i-1];
            int nx=path[i+1];
            for(int son:g[x]){
                if(son!=pre && son!=nx){
                    cout<<pre+1<<" "<<x+1<<" "<<son+1<<'\n';
                    return;
                }
            }
        }
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