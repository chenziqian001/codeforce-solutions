#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=1e5+10;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> dp(N,vector<int>(2));
    int t,k;
    cin>>t>>k;
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<N;i++){
        dp[i][1]+=dp[i-1][0];
        dp[i][1]%=mod;
        dp[i][1]+=dp[i-1][1];
        dp[i][1]%=mod;

        if(i>=k){
            dp[i][0]+=dp[i-k][0];
            dp[i][0]%=mod;
            dp[i][0]+=dp[i-k][1];
            dp[i][0]%=mod;
        }
    }
    vector<int> pre(N);
    for(int i=1;i<N;i++){
        pre[i]=(pre[i-1]+dp[i][1]+dp[i][0])%mod;
    }




    while(t--){
        int l,r;
        cin>>l>>r;
        int res=0;
        res=(pre[r]-pre[l-1]+mod)%mod;
        cout<<res<<'\n';
    }

    //system("pause");
}
