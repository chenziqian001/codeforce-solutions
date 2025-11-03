#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]; 
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    vector<vector<int>> vis(n+1,vector<int>(n+1));
    dp[0][0]=1;
    int res=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        vector<int> v(n+1);
        int mex=0;
        for(int j=i;j>=1;j--){
            v[a[j]]=1;
            if(v[mex]){
                while(v[mex]) mex++;
                if(vis[j][mex]) continue;
                vis[j][mex]=1;
                for(int k=0;k<=j;k++){
                    if(dp[j-1][k]){
                        dp[i][k^mex]=1;
                    }
                }
            }
        }
        for(int k=1;k<=i;k++){
            if(dp[i][k]) res=max(res,k);
        }

    }

    cout<<res<<'\n';
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}