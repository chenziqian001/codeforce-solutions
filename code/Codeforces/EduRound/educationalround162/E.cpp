#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> cnt(n+1);
    int res=0;
    function<void(int,int)> dfs=[&](int node,int fa){
        int s=0;
        for(int next:t[node]){
            if(next==fa) continue;
            int pre=cnt[c[node]];
            dfs(next,node);
            int k=cnt[c[node]]-pre;
            res+=k*(k+1)/2;
            s+=k;
        }
        cnt[c[node]]+=1-s;
    };
    dfs(0,-1);

    for(int i=1;i<=n;i++){
        if(cnt[i]){
            int k=cnt[i];
            res+=k*(k-1)/2;
        }
    }
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