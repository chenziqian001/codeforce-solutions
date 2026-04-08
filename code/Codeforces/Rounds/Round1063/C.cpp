#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(2,vector<int>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    auto pmin=a[0],pmax=a[0],smin=a[1],smax=a[1];

    for(int i=1;i<n;i++){
        pmin[i]=min(pmin[i],pmin[i-1]);
        pmax[i]=max(pmax[i],pmax[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        smin[i]=min(smin[i],smin[i+1]);
        smax[i]=max(smax[i],smax[i+1]);
    }
    vector<int> dp(2*n,2*n);
    for(int i=0;i<n;i++){
        int l=min(pmin[i],smin[i]);
        int r=max(pmax[i],smax[i]);
        dp[l]=min(dp[l],r);
    }

    for(int i=2*n-2;i>=0;i--){
        dp[i]=min(dp[i],dp[i+1]);
    }
    long long res=0;
    
    for(int i=2*n-1;i>=0;i--){
        res+=2*n-dp[i];
    }

    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}