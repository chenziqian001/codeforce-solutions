#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> c(14),v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[x]++;
    }

    for(int i=1;i<=13;i++) if(c[i]) v.push_back(c[i]);
    int m=v.size(),M=1<<m;
    vector<int> dp(M,1e9),s(M);
    dp[0]=0;
    for(int i=1;i<M;i++){
        s[i]=s[i-(i&-i)]+v[__builtin_ctz(i)];
        if(s[i]<=w){
            dp[i]=1;
            continue;
        }
        for(int j=i;j;j=(j-1)&i) dp[i]=min(dp[i],dp[j]+dp[i^j]);
    }
    cout<<dp[M-1]<<'\n';

    

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