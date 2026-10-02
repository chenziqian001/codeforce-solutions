#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b;
    cin>>a>>b;
    //a白b黑
    vector<vector<double>> dp(a+1,vector<double>(b+1));
    for(int i=1;i<=a;i++){
        dp[i][0]=1.0;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            dp[i][j]=(double)i/(i+j);
            if(j>=2) dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
            if(j>=3) dp[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3];
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<dp[a][b]<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    //system("pause");
    return 0;
}
