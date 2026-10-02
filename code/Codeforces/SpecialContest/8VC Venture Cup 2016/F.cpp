#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a.begin()+1,a.end());
    
    vector<vector<int>> dp(n+2,vector<int>(k+1));
    dp[0][0]=1;


    for(int i=1;i<=n;i++){
        vector<vector<int>> ndp(n+2,vector<int>(k+1));
        int d = a[i]-a[i-1];
        for(int j=0;j<=i;j++){
            for(int w=0;w<=k;w++){
                if(!dp[j][w]) continue;
                int nw = w + d*j;
                if(nw>k) continue;
                ndp[j+1][nw]=(ndp[j+1][nw]+dp[j][w])%mod;

                if(j>0)ndp[j-1][nw]=(ndp[j-1][nw]+dp[j][w]*j)%mod;
                
                ndp[j][nw]=(ndp[j][nw]+dp[j][w]*(j+1))%mod;
            }
        }
        dp=ndp;
    }
    int  res=0;
    for(int w=0;w<=k;w++) res=(res+dp[0][w])%mod;
    cout<<res<<'\n';
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


