#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int>> t(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> sz(n);
    int res=inf;
    function<void(int,int)> dfs=[&](int node,int fa){
        sz[node]=1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            sz[node]+=sz[next];
            res=min(res,sz[next]*sz[next]+(n-sz[next])*(n-sz[next]));
        }
    };
    dfs(0,-1);
    cout<<res<<'\n';


}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}