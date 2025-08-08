#include<bits/stdc++.h>
using namespace std;
const int n=60;
const long long inf=8e18;
vector<vector<long long>> dp;
void solve(){
    long long x,y;
    cin>>x>>y;
    long long ans=inf;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if((x>>i)==(y>>j)) ans=min(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
    

}
int main(){
    dp.resize(n+1,vector<long long>(n+1,inf));
    dp[0][0]=0LL;
    for(int k=0;k<n;k++){
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(dp[i][j]==inf) continue;
                if(i+k<=n) dp[i+k][j]=min(dp[i+k][j],dp[i][j]+(1LL<<k));
                if(j+k<=n) dp[i][j+k]=min(dp[i][j+k],dp[i][j]+(1LL<<k));
            }
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}