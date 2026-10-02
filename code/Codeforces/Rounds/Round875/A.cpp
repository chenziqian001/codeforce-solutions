#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;

    vector<vector<pair<int,int>>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].emplace_back(v,i);
        t[v].emplace_back(u,i);
    }
    vector<int> f(n+1),id(n+1);
    id[1]=n+1;
    function<void(int,int)> dfs=[&](int node,int fa){
        for(auto [next,w]:t[node]){
            if(next==fa) continue;
            id[next]=w;
            f[next]=f[node]+(w<id[node]);
            dfs(next,node);
        }
    };
    dfs(1,0);
    int res=*max_element(f.begin()+1,f.end());
    cout<<res<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}