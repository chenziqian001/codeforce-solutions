#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];


    int mx=*max_element(a.begin(),a.end());
    vector<int> cnt(mx+1);


    for(int x:a) cnt[x]++;

    vector<int> dp(mx+1);
    for(int i=1;i<=mx;i++){
        dp[i]+=cnt[i];
        for(int j=i*2;j<=mx;j+=i){
            dp[j]=max(dp[j],dp[i]);
        }
    }


    cout<<n-*max_element(dp.begin(),dp.end())<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}