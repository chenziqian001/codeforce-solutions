#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

int get(vector<int> &a){
    int sz=a.size();
    vector<int> dp(sz+1,inf);
    dp[0]=0;
    for(int i=0;i<sz;i++){
        if(i+2<=sz) dp[i+2]=min(dp[i+2],dp[i]+max(a[i+1],a[i])-min(a[i],a[i+1]));
        if(i+3<=sz) dp[i+3]=min(dp[i+3],dp[i]+max({a[i+2],a[i+1],a[i]})-min({a[i+2],a[i+1],a[i]}));
    }
    return dp[sz];
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=get(a);
    for(int i=0;i<n-1;i++) swap(a[i],a[i+1]);
    res=min(res,get(a));
    for(int i=0;i<n-1;i++) swap(a[i],a[i+1]);
    res=min(res,get(a));
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


