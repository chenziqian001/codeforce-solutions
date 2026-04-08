#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;



void solve(){
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        int v,t;
        cin>>v>>t;
        a[i]={v,t};
    }
    int sz=n*13*2*2;


    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(sz+1,-1e18)));
    dp[0][0][n*13*2]=0;


    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            for(int w=sz;w>=0;w--){
                dp[i][j][w]=dp[i-1][j][w];
                int val=a[i].first;
                int siz=a[i].second;
                if(w>=siz){
                    dp[i][j][w]=max(dp[i][j][w],dp[i-1][j][w-siz]+val);
                }
                if(w+siz<=sz){
                    dp[i][j][w]=max(dp[i][j][w],dp[i-1][j][w+siz]+val);
                }
                if(j){
                    siz*=2;
                    if(w>=siz){
                    dp[i][j][w]=max(dp[i][j][w],dp[i-1][j-1][w-siz]+val);
                    }
                    if(w+siz<=sz){
                        dp[i][j][w]=max(dp[i][j][w],dp[i-1][j-1][w+siz]+val);
                    }
                }
                if(i==n && w==n*13*2){
                    res=max(res,dp[i][j][w]);
                }
            }
        }
    }


    cout<<res<<'\n';





    



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