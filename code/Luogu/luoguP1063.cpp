#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

signed main(){
    int n;
    cin>>n;
    vector<int> a(n*2);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=a[i+n]=x;
    }
    vector<vector<int>> dp(n*2,vector<int>(n*2));
    for(int len=3;len<=n+1;len++){
        for(int l=0;l<2*n-len+1;l++){
            int r=l+len-1;
            if(len==3) dp[l][r]=a[l]*a[l+1]*a[r];
            else{
                for(int k=l+1;k<r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][i+n]);
    }
    cout<<ans<<'\n';
    return 0;
}