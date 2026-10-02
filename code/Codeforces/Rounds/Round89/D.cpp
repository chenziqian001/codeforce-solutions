#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e8;
int dp[110][110][2];

void solve(){
    int n1,n2;
    int k1,k2;
    cin>>n1>>n2>>k1>>k2;
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
           if(i==0 && j==0)  continue;
           for(int k=1;k<=min(i,k1);k++) dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%mod;
           for(int k=1;k<=min(j,k2);k++) dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%mod; 
        }
    }
    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%mod<<'\n';
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