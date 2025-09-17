#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=100;
 
/*void solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<1<<" "<<0<<" "<<1<<'\n';
        return;
    }
    int k=n/2;
    vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(k+1,vector<int>(3)));
    dp[0][0][2]=1;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            for(int t=0;t<3;t++){
                int turn=(i+j)%4;
                if(turn==0 || turn==3){
                    if(j<k) dp[i][j+1][t]=(dp[i][j+1][t]+dp[i][j][t])%mod;
                    if(i<k) dp[i+1][j][t==2?0:t]=(dp[i+1][j][t==2?0:t]+dp[i][j][t])%mod;
                }
                else{
                    if(i<k) dp[i+1][j][t]=(dp[i+1][j][t]+dp[i][j][t])%mod;
                    if(j<k) dp[i][j+1][t==2?1:t]=(dp[i][j+1][t==2?1:t]+dp[i][j][t])%mod;
                }
            }
        }
    }
    cout<<dp[k][k][0]<<" "<<dp[k][k][1]<<" "<<dp[k][k][2]<<'\n';
}*/

int fac(int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res=(res*i)%mod;
    }
    return res;
}
int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int C(int m,int n){
    if(m>n) return 0;
    else return fac(n)*qpow(fac(m),mod-2)%mod*qpow(fac(n-m),mod-2)%mod;
}
vector<int> cal(int n){
    if(n==2){
        return {1,0,1};
    }
    vector<int> pre=cal(n-2);
    int a=(C(n/2,n-1)+pre[1])%mod;
    int b=(C(n/2,n-2)+pre[0])%mod;
    return {a,b,1};
}
void solve(){
    int n;
    cin>>n;
    vector<int> res=cal(n);
    
    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}