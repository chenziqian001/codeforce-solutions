#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,-inf));
    dp[0][0]=0;

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            for(int p=i-1;p>=max(0LL,i-k);p--){
                if(dp[p][j-1]==-inf) continue;
                dp[i][j]=max(dp[i][j],dp[p][j-1]+a[i]);
            }
        }
    }
    int res=-inf;
    for(int i=n-k+1;i<=n;i++){
        res=max(res,dp[i][x]);
    }
    if(res==-inf){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';
    //system("pause");
    return 0;
}