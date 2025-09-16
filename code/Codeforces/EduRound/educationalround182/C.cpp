#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;


void solve(){
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<vector<int>> dp(n,vector<int>(2));
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1] && b[i]>=b[i-1]){
            dp[i][0]=(dp[i][0]+dp[i-1][0])%mod;
            dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;
        }
        if(a[i]>=b[i-1] && b[i]>=a[i-1]){
            dp[i][0]=(dp[i][0]+dp[i-1][1])%mod;
            dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;
        }
    } 

    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}