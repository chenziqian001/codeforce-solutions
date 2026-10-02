#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
 

void solve(){
    int n,c0;
    cin>>n>>c0;
    vector<int> c(n-1);
    for(int i=0;i<n-1;i++) {
        cin>>c[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n+1,n);
    int res=n;
    auto bfs = [&](int s) {
        queue<int> q;
        q.push(s);
        d[s]=0;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            if(d[u]>=res) continue;
            for(int v:g[u]) {
                if(d[u]+1<min(res,d[v])) {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
    };
    
    bfs(c0);
    for(int i=0;i<n-1;i++){
        res=min(res,d[c[i]]);
        bfs(c[i]);
        cout<<res<<" ";
    }
    cout<<'\n';
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