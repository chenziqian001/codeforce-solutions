#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> h(n);
    int res=0;

    function<void(int,int)> dfs=[&](int node,int fa){
        h[node]=1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            h[node]=max(h[node],h[next]+1);
        }
        res=(res+h[node])%mod;
    };
    dfs(0,-1);
 
    res=res*qp(2,n-1)%mod;
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