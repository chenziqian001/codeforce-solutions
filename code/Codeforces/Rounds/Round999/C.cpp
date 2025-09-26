#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            dp[i]=(dp[i-1]+dp[i])%mod;
        }
        if(i>1 && a[i]==(a[i-2]+1)){
            dp[i]=(dp[i]+dp[i-2])%mod;
        }
    }
    cout<<(dp[n]+dp[n-1])%mod<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}