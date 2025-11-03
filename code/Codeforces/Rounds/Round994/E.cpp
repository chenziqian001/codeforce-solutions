#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,m,K;
    cin>>n>>m>>K;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    vector<int> dp(m,inf);
    
    dp[0]=0;
    
    for(int i=0;i<n;i++){
        vector<int> ndp(m,inf);
        for(int k=0;k<m;k++){
            auto g=dp;
            for(int j=0;j<m;j++){
                if(j){
                    g[j]=min(g[j],g[j-1]);
                }
                g[j]+=a[i][(j+k)%m];
                ndp[j]=min(ndp[j],g[j]+k*K);
            }
        }
        dp=move(ndp);
    }
    cout<<dp[m-1]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}