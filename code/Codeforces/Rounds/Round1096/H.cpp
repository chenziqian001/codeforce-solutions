#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> sz(n,0);
    int k=0;
    for(int i=0;i<n;i++){
        if(t[i].size()==1) k++;
    }
    function<void(int,int)> dfs1=[&](int u,int fa){
        if(t[u].size()==1) sz[u]=1;
        for(int v:t[u]){
            if(v==fa) continue;
            dfs1(v,u);
            sz[u]+=sz[v];
        }
    };
    dfs1(0,-1);
    int base=0;
    for(int i=1;i<n;i++){
        if(sz[i]%2!=0) base++;
    }
    if(k%2==0){
        cout<<base<<'\n';
        return;
    }
    int res=1e18;
    function<void(int,int,int)> dfs2=[&](int u,int fa,int c){
        if(t[u].size()==1) res=min(res,c);
        for(int v:t[u]){
            if(v==fa) continue;
            dfs2(v,u,c+(sz[v]%2==0?1:-1));
        }
    };
    dfs2(0,-1,base);
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