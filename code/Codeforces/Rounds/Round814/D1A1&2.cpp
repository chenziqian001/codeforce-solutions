#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1);
    int pre=0;
    map<int,int> mp;
    
    mp[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            mp[pre]=i;
            dp[i]=dp[i-1];
            continue;
        }
        pre^=a[i];
        dp[i]=dp[i-1]+1;
        if(mp.count(pre)){
            int j=mp[pre];
            dp[i]=min(dp[i],dp[j]+i-j-1);
        }
        mp[pre]=i;
    }

    cout<<dp[n]<<'\n';
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