#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> t(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> dp(n);
    int res=0;
    function<void(int,int)> dfs=[&](int node,int fa){
        res=max(res,a[node]);
        dp[node]=a[node];
        vector<int> v1,v2;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            if(dp[next]>0) v1.push_back(dp[next]);
            else v2.push_back(dp[next]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(!v1.empty()){
            dp[node]=max(dp[node],v1.back());
            res=max(res,v1.back()+a[node]);
        }
        if(!v2.empty()){
            dp[node]=max(dp[node],v2.back());
            res=max(res,v2.back()+a[node]);
        }
        if(v1.size()>1){
            int s=a[node];
            for(int x:v1) s+=x;
            dp[node]=max(dp[node],s);
            res=max(res,v1.back()+v1[v1.size()-2]);
            if(v1.size()>2) res=max(res,s);
        }
        if(v1.size()==2 && !v2.empty()){
            res=max(res,v1.back()+v1[v1.size()-2]+a[node]+v2.back());
        }
        if(v1.size()==1 && !v2.empty()){
            dp[node]=max(dp[node],a[node]+v1.back()+v2.back());
            res=max(res,v1.back()+v2.back());
        }        
        
    };
    dfs(0,-1);
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



