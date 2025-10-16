#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;



void solve(){
    int n,t;
    cin>>n>>t;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n);
    vector<int> dep(n);
    vector<int> p(n);
    function<void(int,int)> dfs=[&](int u,int fa){
        if(dep[u]==1) d[u]=1;
        if(dep[u]>1) d[u]=d[p[fa]]+2*(int)g[fa].size();
        p[u]=fa;
        for(int v:g[u]){
            if(v==fa) continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
    };
    dfs(0,0);

    while(t--){
        int u,q;
        cin>>u>>q;

        u--;
        int res=d[u];
        vector<int> path;
        while(n!=0 && p[u]!=0){
            path.push_back((int)g[p[u]].size());
            u=p[p[u]];
        }
        sort(path.rbegin(),path.rend());
        for(int i=0;i<min(q,(int)path.size());i++){
            res=res-2*(path[i]-1);
        }
        cout<<res<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}