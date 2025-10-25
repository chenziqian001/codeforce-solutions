#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1,inf);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int p=i+1;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[p]) p=j;
        }
        for(int j=p;j<=n;j++){
            dp[i]=min(dp[i],dp[j]+a[p]*(j-i)+2*(j-p)+(p-i-1));
        }
    }
    cout<<dp[0]<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}





