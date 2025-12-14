#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
   
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<vector<int>> dp(n+1,vector<int>(2));
    for(int i=1;i<=n;i++){
        dp[i][0]=max({dp[i-1][0]-a[i],dp[i-1][1]-a[i],b[i]-dp[i-1][0],b[i]-dp[i-1][1]});
        dp[i][1]=min({dp[i-1][0]-a[i],dp[i-1][1]-a[i],b[i]-dp[i-1][0],b[i]-dp[i-1][1]});
    }

    cout<<dp[n][0]<<'\n';


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
