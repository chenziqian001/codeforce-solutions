#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x) {return qp(x,mod-2);}//逆元



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> dp(2005,vector<int>(2005));
    for(int i=1;i<=2000;i++){
        dp[i][i]=i;
        for(int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod*inv(2)%mod;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m]*k%mod<<'\n';
    }
    //system("pause");

}