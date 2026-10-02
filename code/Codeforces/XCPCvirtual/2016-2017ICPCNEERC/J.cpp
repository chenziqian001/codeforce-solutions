#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int s=accumulate(a.begin(),a.end(),0LL);
    int v=accumulate(b.begin(),b.end(),0LL);
    vector<vector<int>> dp(n+1,vector<int>(v+1,-1));
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            for(int k=v;k>=b[i-1];k--){
                if(dp[j-1][k-b[i-1]]!=-1) dp[j][k]=max(dp[j][k],dp[j-1][k-b[i-1]]+a[i-1]);
            }
        }
    }
    for(int j=1;j<=n;j++){
        int mx=-1;
        for(int k=s;k<=v;k++){
            if(dp[j][k]!=-1) mx=max(mx,dp[j][k]);
        }
        if(mx!=-1){
            cout<<j<<" "<<s-mx<<'\n';
            return;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}