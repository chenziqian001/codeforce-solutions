#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
}
signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}