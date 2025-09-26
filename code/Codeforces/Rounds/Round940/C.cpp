#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    int used=0;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        used+=2-(x==y);
    }
    int re=n-used;
    if(re==0){
        cout<<1<<'\n';
        return;
    }
    vector<int> dp(re+1);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=re;i++){
        dp[i]=(dp[i-1]+2*(i-1)%mod*dp[i-2]%mod)%mod;
    }
    cout<<dp[re]<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}