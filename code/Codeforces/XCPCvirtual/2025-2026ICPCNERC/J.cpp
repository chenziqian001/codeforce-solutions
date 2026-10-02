#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<double> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]/=100.0;
    }
    vector<vector<double>> dp(k+1,vector<double>(k+1,0.0));
    for(int w=0;w<=k;w++){
        int l=k-w;
        for(int i=0;i<n;i++){
            dp[w][l]+=pow(p[i],w)*pow(1.0-p[i],l);
        }
    }
    for(int s=k-1;s>=0;s--){
        for(int w=0;w<=s;w++){
            int l=s-w;
            dp[w][l]=max(dp[w+1][l]+dp[w][l+1],2.0*dp[w+1][l]);
        }
    }
    cout<<fixed<<setprecision(6)<<1000.0*(dp[0][0]/n-1.0)<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}