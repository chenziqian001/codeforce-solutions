#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<string> a(2);
    cin>>a[0];cin>>a[1];
    a[0]+='#';
    a[1]+='#';
    vector<vector<int>> dp(2,vector<int>(n+1));
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++){
            if(a[i][j]=='#') dp[i][j]=1;
        }
    }
    int mul=false;
    for(int j=0;j<n;j++){
        if(!dp[0][j] && !dp[1][j]){
            if(!dp[0][j+1] && !dp[1][j+1]){
                mul=true;
                dp[0][j+1]=dp[1][j+1]=1;
            }
            if(dp[1][j+1] || dp[0][j+1]){
                dp[0][j]=dp[1][j]=1;
            }
        }
        if(!dp[0][j] && dp[1][j]){
            if(!dp[0][j+1]) dp[0][j]=dp[0][j+1]=1;
            else{
                cout<<"None"<<'\n';
                return;
            }
        }
        if(!dp[1][j] && dp[0][j]){
            if(!dp[1][j+1])dp[1][j]=dp[1][j+1]=1;
            else{
                cout<<"None"<<'\n';
                return;
            }
        }
    }
    if(mul){
        cout<<"Multiple"<<'\n';
    }
    else{
        cout<<"Unique"<<'\n';

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}