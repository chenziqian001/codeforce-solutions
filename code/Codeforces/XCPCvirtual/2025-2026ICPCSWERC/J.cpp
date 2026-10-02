#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for(int j=1;j<=m;j++){
        vector<bool> ndp(n+1,false);
        int p=1e9;
        for(int i=0;i<=n;i++){
            if(dp[i]){
                p=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(dp[i-1] && a[i]==b[j]) ndp[i]=true;
            if(i-p>=b[j]) ndp[i]=true;
        }
        dp=ndp;
    }
    if(dp[n]) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
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