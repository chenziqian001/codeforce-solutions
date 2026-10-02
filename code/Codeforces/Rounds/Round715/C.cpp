#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    vector<int> dp(n);

    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            dp[i]=a[i+l-1]-a[i]+min(dp[i+1],dp[i]);
        }
    }
    cout<<dp[0]<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}