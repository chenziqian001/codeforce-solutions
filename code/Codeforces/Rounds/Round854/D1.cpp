#include<bits/stdc++.h>
using namespace std;


#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> c(k+1);
    vector<int> h(k+1);
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=1;i<=k;i++) cin>>h[i];

    vector<int> dp(k+1,1e18);


    dp[0]=0;
    int mini=0;
    int tt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            tt+=h[a[i]];
        }
        else{
            tt+=c[a[i]];
            dp[a[i-1]]=min(mini,dp[a[i]]-c[a[i]]+h[a[i]]);
            mini=min(mini,dp[a[i-1]]);

        }
    }


    cout<<mini+tt<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}