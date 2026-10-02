#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> d(n),c(n,0);
    for(int i=0;i<n;i++){
        d[i]=t[i].size();
        for(int v:t[i]){
            if(s[v]=='1') c[i]++;
        }
    }
    vector<bool> vis(n,false);
    vector<vector<double>> dp(n,vector<double>(2,0));
    function<void(int,int)> dfs=[&](int node,int fa){
        vis[node]=true;
        double b=0;
        vector<double> diff;
        for(int next:t[node]){
            if(next==fa) continue;
            if(s[next]=='1') continue;
            dfs(next,node);
            b+=dp[next][1];
            diff.push_back(dp[next][0]-dp[next][1]);
        }
        sort(diff.begin(),diff.end());
        int sz=diff.size();
        vector<double> pre(sz+1);
        for(int i=0;i<sz;i++) pre[i+1]=pre[i]+diff[i];
        for(int i=0;i<2;i++){
            double val=1e18;
            for(int j=0;j<=sz;j++){
                int in=c[node]+i+j;
                if(in<=0) continue;
                double cur=(double) d[node]/in+b+pre[j];
                val=min(val,cur);
            }
            dp[node][i]=val;
        }
    };
    double res=0;
    for(int i=0;i<n;i++){
        if(!vis[i] && s[i]=='0'){
            dfs(i,-1);
            res+=dp[i][0];
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<res<<'\n';

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