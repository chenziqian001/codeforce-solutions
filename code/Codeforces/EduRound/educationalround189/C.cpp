#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;

void solve(){
    int n;
    cin>>n;
    vector<string> s(2);
    string a,b;
    cin>>a>>b;
    a='?'+a;
    b='?'+b;
    s[0]=a,s[1]=b;
    vector<int> dp(n+1,inf);
    dp[0]=0;
    dp[1]=(s[1][1]!=s[0][1]);
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+(s[0][i]!=s[1][i]),dp[i-2]+(s[0][i]!=s[0][i-1])+(s[1][i]!=s[1][i-1]));
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

