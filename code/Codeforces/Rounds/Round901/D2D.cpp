#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    

    vector<int> cnt(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=n)cnt[x]++;
    }

    int mex=0;
    while(cnt[mex]) mex++;

    vector<int> dp(mex+1,1e18);
    dp[mex]=0;
    for(int i=mex;i>=1;i--){
        for(int j=0;j<i;j++){
            dp[j]=min(dp[j],dp[i]+i*(cnt[j]-1)+j);
        }
    }
    cout<<dp[0]<<'\n';


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
