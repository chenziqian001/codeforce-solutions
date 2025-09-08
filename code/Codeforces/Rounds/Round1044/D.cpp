#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
void solve(){
    int n;
    cin>>n;
    vector<long long> h(n+1);
    for(int i=1;i<=n;i++) cin>>h[i];
    vector<long long> dp(n+2,inf);
    dp[0]=0;
    dp[1]=h[1];
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+h[i]-1LL,dp[i-2]+h[i-1]+max(h[i]-i+1,0LL));
    }
    cout<<dp[n]<<'\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}