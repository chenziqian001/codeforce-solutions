#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        n>>=1;
        a=a*a%mod;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];

    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> f(n+1),sz(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        sz[node]=1;
        int cur=1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            sz[node]+=sz[next];
            cur=cur*f[next]%mod;
        }
        f[node]=(cur+(c[node]==1?qp(2,sz[node]-1):0))%mod;
    };

    dfs(1,0);
    cout<<f[1]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}