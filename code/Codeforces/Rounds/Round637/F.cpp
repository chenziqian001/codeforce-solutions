#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> ans(n+1);
    vector<int> val(n+1);
    function<void(int,int)> dfs1=[&](int node,int fa){
        val[node]=(a[node]==1?1:-1);
        for(int next:t[node]){
            if(next==fa) continue;
            dfs1(next,node);
            val[node]+=(val[next]>=0?val[next]:0);
        }
    };
    dfs1(1,0);
    ans[1]=val[1];
    
   function<void(int,int)> dfs2=[&](int node,int fa){
        for(int next:t[node]){
            if(next==fa) continue;
            ans[next]=val[next]+max(0LL,ans[node]-max(0LL,val[next]));
            dfs2(next,node);
        }
    };
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';


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