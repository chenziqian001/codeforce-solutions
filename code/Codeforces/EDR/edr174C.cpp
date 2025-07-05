#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long dp[4]={1LL,0LL,0LL,0LL};
    for(int x:a){
        if(x==2) dp[2]=(dp[2]+dp[2])%M;
        dp[x]=(dp[x]+dp[x-1])%M;
    }
    cout<<dp[3]<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}