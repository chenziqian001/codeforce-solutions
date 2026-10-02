#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> c(m+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[x]++;
    }
    vector<vector<int>> dp(3,vector<int>(3,-1));
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        vector<vector<int>> ndp(3,vector<int>(3,-1));
        for(int l=0;l<3;l++){
            for(int j=0;j<3;j++){
                if(dp[l][j]==-1) continue;
                for(int k=0;k<3;k++){
                    if(c[i]>=l+j+k){
                        ndp[j][k]=max(ndp[j][k],dp[l][j]+k+(c[i]-l-j-k)/3);
                    }
                }
            }
        }
        dp=ndp;
    }
    cout<<dp[0][0]<<'\n';
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

