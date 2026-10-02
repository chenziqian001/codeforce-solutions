#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,mod;
    cin>>n>>k>>mod;
    
    vector<vector<int>> dp(k+1,vector<int>(k+1));
    for(int y=0;y<=k;y++){
        dp[0][y]=1;
    }
    for(int i=2;i<=n;i++){
        vector<vector<int>> suf(k+2,vector<int>(k+1));
        for(int y=0;y<=k;y++){
            for(int x=k;x>=0;x--){
                suf[x][y]=(suf[x+1][y]+dp[x][y])%mod; 
            }
        }
        vector<vector<int>> ndp(k+1,vector<int>(k+1));
        for(int y=0;y<=k;y++){
            for(int z=0;z<=k;z++){
                int d=max(0LL,y-z);
                ndp[y][z]=suf[d][y];
            }
        }
        dp=ndp;
    }

    int res=0;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=x;y++){
            res=(res+dp[x][y])%mod;
        }
    }
    cout<<res<<'\n';
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

