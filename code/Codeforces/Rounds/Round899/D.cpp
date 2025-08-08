#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> t(n + 1);
    vector<long long> ans(n+1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<long long> size(n+1);
    function<void(int,int)> dfs;
    dfs=[&](int node,int fa){
        size[node]=1LL;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            size[node]+=size[next];
            ans[node]+=ans[next]+(a[node]^a[next])*size[next];
        }

    };
    dfs(1,-1);
    function<void(int,int,long long)> change_root;
    change_root=[&](int node,int fa,long long val){
        ans[node]=val;
        for(int next:t[node]){
            if(next==fa) continue;
            change_root(next,node,val-size[next]*(a[node]^a[next])+(n-size[next])*(a[node]^a[next]));
        }

    };
    change_root(1,-1,ans[1]);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    

    
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}