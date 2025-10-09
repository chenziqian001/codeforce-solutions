#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> l(n),r(n),a(n);
    for(int i=0;i<n;i++) cin>>l[i]>>r[i];
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    } 
    long long ans=0;
    function<void(int,int)> dfs=[&](int u,int fa){
        int mx=l[u];
        for(int v:t[u]){
            if(v==fa) continue;
            dfs(v,u);
            mx=max(mx,a[v]);
        }
        a[u]=min(mx,r[u]);
        for(int v:t[u]){
            if(v==fa) continue;
            ans+=max(0,a[v]-a[u]);
        }
    };
    dfs(0,-1);
    ans+=a[0];
    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}