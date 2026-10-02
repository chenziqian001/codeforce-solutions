#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int dp[5005],cnti[5005],cntp[5005];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            for(int j=1;j<=m;j++){
                cntp[j]+=cntp[j-1];
                cnti[j]+=cnti[j-1];
            }
            for(int j=0;j<=k;j++){
                dp[j]+=cnti[j]+cntp[k-j];
            }
            for(int j=k+1;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]);
            }
            k++;
            for(int j=0;j<=m;j++){
                cnti[j]=0;
                cntp[j]=0;
            }
        }
        else if(a[i]<0){cntp[-a[i]]++;}
        else{cnti[a[i]]++;}
    }
    for(int j=1;j<=m;j++){
        cnti[j]+=cnti[j-1];
        cntp[j]+=cntp[j-1];
    }
    int res=0;
    for(int j=0;j<=k;j++){
        dp[j]+=cnti[j]+cntp[k-j];
        res=max(res,dp[j]);
    }
    cout<<res<<'\n';
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
