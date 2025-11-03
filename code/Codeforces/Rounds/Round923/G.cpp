#include<bits/stdc++.h>
using namespace std;





void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX)));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dp[i][j][k]==INT_MAX) continue;
                {
                    int ni=i+1;
                    int nj=j>0?j+1:(k==0)?1:0;
                    int nk=max(0,k-1);
                    dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]);
                }//不炸
                {
                    int ni=i+1;
                    int nj=j>0?j+1:0;
                    int nk=max(0,k-1);
                    if(a[i]>=nj){
                        nj=0;
                    }
                    dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]+1);                    
                }//往左炸

                {
                    int ni=i+1;
                    int nj=j>0?j+1:0;
                    int nk=max(a[i]-1,k-1);
                    dp[ni][nj][nk]=min(dp[ni][nj][nk],dp[i][j][k]+1);
                }
            }
        }
    }

    cout<<*min_element(dp[n][0].begin(),dp[n][0].end())<<'\n';
}






int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}