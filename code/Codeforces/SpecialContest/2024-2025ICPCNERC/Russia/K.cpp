#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
const int N=1e6+10;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> ga(n+1);
    vector<int> gb(n+1);
    int maxi=1;
    for(int i=1;i<=n;i++){
        ga[i]=gcd(a,i);
        if(ga[i]==1){
            maxi=i;
        }
    }
    int maxj=1;
    for(int j=1;j<=n;j++){
        gb[j]=gcd(b,j);
        if(gb[j]==1){
            maxj=j;
        }
    }
    int res=maxi+maxj-2;
    for(int j=1;j<=maxj;j++){
        res+=gb[j];
    }
    for(int i=1;i<=maxi;i++){
        res+=ga[i];
    }
    
    vector<vector<int>> dp(n-maxi+1,vector<int>(n-maxj+1,inf));
    dp[0][0]=0;
    for(int i=0;i<=n-maxi;i++){
        for(int j=0;j<=n-maxj;j++){
            if(i>0){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+ga[i+maxi]+gb[j+maxj]);
            }
            if(j>0){
                dp[i][j]=min(dp[i][j],dp[i][j-1]+ga[i+maxi]+gb[j+maxj]);
            }
        }
    }

    res+=dp[n-maxi][n-maxj];
    cout<<res<<'\n';
    
    //system("pause");
}
