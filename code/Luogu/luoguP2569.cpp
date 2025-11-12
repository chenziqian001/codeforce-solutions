#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,mxp,w;
    cin>>t>>mxp>>w;
    int q[2001];
    vector<vector<int>> dp(2001,vector<int>(2001,-inf));
    for(int i=1;i<=t;i++){
        int ap,bp,as,bs;
        cin>>ap>>bp>>as>>bs;
        for(int j=0;j<=as;j++){
            dp[i][j]=-1*j*ap;
        }
        for(int j=0;j<=mxp;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
        if(i<=w) continue;
        int l=1,r=0;
        for(int j=0;j<=mxp;j++){
            while(l<=r && q[l]<j-as){
                l++;
            }
            while(l<=r && dp[i-w-1][q[r]]+q[r]*ap<=dp[i-w-1][j]+j*ap){
                r--;
            }
            q[++r]=j;
            if(l<=r){
                dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]+q[l]*ap-j*ap);
            }
        }
        l=1,r=0;
        for(int j=mxp;j>=0;j--){
            while(l<=r && q[l]>j+bs){
                l++;
            }
            while(l<=r && dp[i-w-1][q[r]]+q[r]*bp<=dp[i-w-1][j]+j*bp){
                r--;
            } 
            q[++r]=j;
            if(l<=r){
                dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]+q[l]*bp-j*bp);
            }
        }
    }
    int res=-inf;
    for(int i=0;i<=mxp;i++){
        res=max(res,dp[t][i]);
    }
    cout<<res<<'\n';
    //system("pause");
    return 0;
}