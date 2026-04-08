#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    vector<int> dp(n+1);
    vector<int> pm(n+1);
    for(int i=1;i<=n;i++){
        int x=i-a[i];
        
        int val1=dp[max(0LL,x)]+a[i]-1;
        int val2=1e18;
        if(x>=1){
            val2=pm[x-1]+i-1;
        }
        dp[i]=min(val1,val2);
        pm[i]=min(pm[i-1],dp[i]-i);
    }

    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        int res=upper_bound(dp.begin(),dp.end(),n-k)-(dp.begin()+1);
        cout<<res<<'\n';
    }    
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