#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(3));
    int res=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0]+a[i],a[i]);
        dp[i][1]=max({dp[i-1][0]+a[i]*x,dp[i-1][1]+a[i]*x,a[i]*x});
        dp[i][2]=max({dp[i-1][2]+a[i],dp[i-1][1]+a[i],a[i]});
        res=max({dp[i][0],dp[i][1],dp[i][2],res});
    }
    cout<<res<<'\n';
    //system("pause");
    return 0;
}