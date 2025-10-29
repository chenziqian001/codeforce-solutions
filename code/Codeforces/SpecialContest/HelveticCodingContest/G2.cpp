#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=2e5+10;

void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    int cnt;
    vector<int> a(m);
    vector<int> b(m);
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        cin>>a[i];cin>>b[i];
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
    }
    vector<int> vis(n+1);
    int d;
    function<int(int)> dfs=[&](int node)->int{
        int res=vis[node]=1;
        for(int i:g[node]){
            if(i==d) continue;
            int next=a[i]^b[i]^node;
            if(vis[next]) continue;
            res+=dfs(next);
        }
        return res;
    };
    
    auto calc=[&](){
        cnt=0;
        bitset<N+1> dp;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int sz=dfs(i);
            cnt++;
            dp|=(dp<<sz);
        }
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
        for(int i=n/2;i>0;i--){
            if(dp[i]) return i;
        }
        return 0LL;
    };
    
    int res=0;
    for(d=0;d<=m;d++){
        res=max(res,calc());
    }
    if(res){
        cout<<res*res+(n-res)*(n-res)+c*(cnt-1)<<'\n';
    }
    else cout<<-1<<'\n';

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}