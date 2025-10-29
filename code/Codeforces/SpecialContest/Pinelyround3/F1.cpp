#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[n-1]!=n || a[0]>1){
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>2 || a[i]-a[i-1]<0){
            cout<<0<<'\n';
            return;
        }
    }
    vector<int> dp(n);
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) dp[i]=dp[i-1];
        else if(a[i]==a[i-1]+1){
            dp[i]=(dp[i]+dp[i-1])%mod;
            dp[i]=(dp[i]+dp[i-1]*(i-a[i-1])%mod)%mod;
            dp[i]=(dp[i]+dp[i-1]*(i-a[i-1])%mod)%mod;
        }
        else dp[i]=dp[i-1]*(i-a[i-1])%mod*(i-a[i-1])%mod;
    }
    cout<<dp[n-1]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
