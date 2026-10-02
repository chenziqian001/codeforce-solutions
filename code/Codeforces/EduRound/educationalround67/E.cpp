#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);t[v].push_back(u);
    }
    vector<int> sz(n+1);
    int res=0;
    int cur=0;
    function<void(int,int)> dfs=[&](int node,int fa){
        int x=1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            x+=sz[next];
        }
        sz[node]=x;
        cur+=sz[node];
    };
    dfs(1,0);
    function<void(int,int,int)> get=[&](int node,int fa,int val){
        res=max(res,val);
        for(int next:t[node]){
            if(next==fa) continue;
            get(next,node,val-2*sz[next]+n);
        }
    };
    get(1,0,cur);
    cout<<res<<'\n';


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}