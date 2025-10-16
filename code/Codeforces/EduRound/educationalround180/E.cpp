#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int inf=1e9;
vector<int> dp;
void solve(){
    int m;
    cin>>m;
    cout<<((dp[m]==inf)?-1:dp[m])<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp.resize(N,inf);
    dp[1]=1;
    for(int m=2;m<N;m++){
        for(int i=1;i*i<=m;i++){
            if(m%i!=0) continue;
            if(m/i>2) dp[m]=min(dp[m/i-2]+dp[i],dp[m]);
            if(i>2) dp[m]=min(dp[m],dp[m/i]+dp[i-2]);
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}