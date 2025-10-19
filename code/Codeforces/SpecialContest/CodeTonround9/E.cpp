#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


void solve(){
    int n;
    cin>>n;
    
    vector<int> dp(n+1);
    dp[n]=1;
    int sum=1;
    for(int i=n-1;i>=1;i--){
        dp[i]=(i*sum%mod+1)%mod;
        sum=(sum+dp[i])%mod;
    }
    int ans=n-1;
    for(int m=3;m<=n;m++){
        int ways=((m-1)*(m-2)/2-1+mod)%mod;
        ans+=ways*dp[m]%mod;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
signed main(){
    int  t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}


