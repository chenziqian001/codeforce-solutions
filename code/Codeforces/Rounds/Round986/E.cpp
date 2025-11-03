#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> dis(n,n);
    function<void(int,int)> dfs1=[&](int node,int fa){
        if(t[node].size()==1 && fa!=-1){
            dis[node]=0;
            return;
        }
        for(int next:t[node]){
            if(next==fa) continue;
            dfs1(next,node);
            dis[node]=min(dis[node],dis[next]+1);
        }
    };
    dfs1(0,-1);
    vector<int> dp(n);
    dp[0]=1;
    function<void(int,int)> dfs2=[&](int node,int fa){
        
        for(int next:t[node]){
            if(next==fa) continue;
            dp[next]=dis[next]*inv(dis[next]+1)%mod*dp[node]%mod;
            dfs2(next,node);
        }
    };
    dfs2(0,-1);
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    cout<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
