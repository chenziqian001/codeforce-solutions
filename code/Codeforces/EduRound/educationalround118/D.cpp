#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;



void solve(){
    int n;
    cin>>n;

    vector<vector<int>> dp(n+5,vector<int>(2));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        x++;
        dp[x][0]=(dp[x][0]+dp[x][0])%mod;
        dp[x][0]=(dp[x][0]+dp[x-1][0])%mod;
        dp[x][1]=(dp[x][1]+dp[x][1])%mod;
        dp[x+2][1]=(dp[x+2][1]+dp[x+2][1])%mod;
        if(x>1) dp[x][1]=(dp[x][1]+dp[x-2][0])%mod;
    }

    int res=0;
    for(int i=1;i<=n+1;i++){
        res=(res+dp[i][0]+dp[i][1])%mod;
    }
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