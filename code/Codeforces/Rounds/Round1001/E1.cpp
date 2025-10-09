#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> w(n+1);
    for(int i=1;i<=n;i++) cin>>w[i];
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> dfn(n+1);
    vector<int> nfd(n+1);
    vector<int> low(n+1);
    int id=0;
    function<void(int,int)> dfs=[&](int node,int fa){
        dfn[node]=++id;
        nfd[id]=node;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
        }
        low[node]=id;
    };
    dfs(1,0);
    vector<int> pre(n+1);
    vector<int> suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],w[nfd[i]]);
    for(int i=n;i>0;i--) suf[i]=max(suf[i+1],w[nfd[i]]);
    int mx=0;
    for(int i=1;i<=n;i++){
        if(max(pre[dfn[i]-1],suf[low[i]+1])>w[i] && w[i]>w[mx]) mx=i;
    }
    cout<<mx<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}