#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int c1=0;
    for(char c:s){
        c1+=(c=='1');
    }

    vector<vector<int>> dp(c1+1,vector<int>(c1*(n-1)/2+1,1e9));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        int val=s[i]=='0';
        for(int j=min(i+1,c1);j>=1;j--){
            for(int k=c1*(n-1)/2;k>=0;k--){
                if(i>k) continue;
                if(dp[j-1][k-i]==1e9) continue;
                dp[j][k]=min(dp[j][k],dp[j-1][k-i]+val);
            }
        }
    }
    cout<<dp[c1][c1*(n-1)/2]<<'\n';



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