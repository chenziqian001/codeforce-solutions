#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    vector<vector<int>> nxt(n+1,vector<int>(m+1));
    for(int k=1;k<=m;k++){
        int r=0;int sum=0;
        for(int i=1;i<=n;i++){
            while(r<=n && sum<=b[k]) sum+=a[++r];
            nxt[i][k]=r;
            sum-=a[i];
        }
    }
    vector<vector<int>> dp(n+2,vector<int>(m+1,inf));
    dp[1][1]=0;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            dp[nxt[i][k]][k]=min(dp[nxt[i][k]][k],dp[i][k]+m-k);
            if(k<m){
                dp[i][k+1]=min(dp[i][k+1],dp[i][k]);
            }
        }
    }
    int res=inf;
    for(int k=1;k<=m;k++){
        res=min(res,dp[n+1][k]);
    }
    if(res==inf){
        cout<<-1<<'\n';
    }
    else{
        cout<<res<<'\n';
    }
    



}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
