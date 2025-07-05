#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,e;
    cin>>n>>s>>e;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dis(n+1);
    vector<vector<int>> cast(n+1); 
    cast[0].push_back(e);
    function<void(int,int)> dfs;
    dfs=[&](int node,int fa){
        dis[node]=dis[fa]+1;
        cast[dis[node]].push_back(node);
        for(int next:g[node]){
            if(next==fa) continue;
            dfs(next,node);
        }
    };
    dfs(e,0);

    for(int i=n;i>=1;i--){
        for(int nd:cast[i]){
            cout<<nd<<" ";
        }
    }
    cout<<'\n';
    return;

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}