#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),t(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> f(n+1);
    vector<int> sum(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        int mx=0,id1=0,id2=0;
        for(int next:g[node]){
            if(next==fa)continue;
            dfs(next,node);
            sum[node]+=f[next];
            mx=max(mx,a[next]);
            if(t[next]==3){
                if(!id1||a[next]>a[id1]){
                    id2=id1;id1=next;
                }else if(!id2||a[next]>a[id2]){
                    id2=next;
                }
            }
        }
        f[node]=sum[node]+mx;
        for(int next:g[node]){
            if(next==fa)continue;
            int w=(id1==next?id2:id1);
            if(w){
                f[node]=max(f[node],sum[node]-f[next]+a[next]+sum[next]+a[w]);
            }
        }
    };
    dfs(1,0);
    cout<<a[1]+f[1]<<'\n';
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
