#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x%2;
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(4,vector<int>(8)));
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=3;j++){
            for(int s=0;s<8;s++){
                if(dp[i][j][s]==0) continue;
                dp[i+1][j][s]=(dp[i+1][j][s]+dp[i][j][s])%mod;
                int nx=((s+8*a[i])>>1);
                if(min(3,j+1)<=2 || __builtin_popcount(nx)%2==0){
                    dp[i+1][min(3,j+1)][nx]=(dp[i+1][min(3,j+1)][nx]+dp[i][j][s])%mod;
                }
            }
        }
    }

    int res=0;
    for(int i=0;i<8;i++){
        res=(res+dp[n][3][i])%mod;
    }

    cout<<res<<'\n';
    system("pause");
    return 0;


}
