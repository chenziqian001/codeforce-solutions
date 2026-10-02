#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<vector<int>>in(n+1);
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        for(int j=0;j<s;j++){
            int x;
            cin>>x;
            in[i].push_back(x);
        }
        sort(in[i].begin(),in[i].end());
    }

    vector<int>a(m+1);
    for(int i=1;i<=m;i++)cin>>a[i];

    vector<int> dp(m+2),lst(n+1),len(n+1);
    for(int i=m;i>=1;i--){
        dp[i]=dp[i+1]+1;
        for(int x:in[a[i]]){
            if(lst[x]==i+1) len[x]++;
            else len[x]=1;
            lst[x]=i;
            int j=i+len[x];
            int val=(j>m)?1:(binary_search(in[x].begin(),in[x].end(),a[j])?dp[j]+1:dp[j+1]+1);
            dp[i]=min(dp[i],val);
        }
    }
    cout<<dp[1]<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}