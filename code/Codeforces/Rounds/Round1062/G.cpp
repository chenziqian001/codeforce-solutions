#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int tt=0;
    vector<int> a(n);
    vector<int> c(n);
    vector<int> dp(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>c[i];

    for(int i=0;i<n;i++){
        dp[i]=c[i];
        tt+=c[i];
    } 


    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i]) continue;
            dp[i]=max(dp[i],dp[j]+c[i]);
        }
    }

    int mxk=0;
    for(int i=0;i<n;i++) mxk=max(mxk,dp[i]);
    cout<<tt-mxk<<'\n';

}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}