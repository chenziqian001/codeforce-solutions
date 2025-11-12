#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int m=2*n;
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-inf)));
    int p=0;
    dp[p][1][1]=a[1][1];
    for(int k=3;k<=m;k++){
        p^=1;
        for(int i=1;i<=n;i++){
            int ii=k-i;
            if(ii<1 || ii>n) continue;
            for(int j=1;j<=n;j++){
                int jj=k-j;
                if(jj<1 || jj>n) continue;
                dp[p][i][j]=max({dp[p^1][i-1][j],dp[p^1][i][j-1],dp[p^1][i-1][j-1],dp[p^1][i][j]})+(i==j?a[i][k-i]:a[i][k-i]+a[j][k-j]);
            }
        }
    }
    cout<<dp[p][n][n]<<'\n';
    //system("pause");
}