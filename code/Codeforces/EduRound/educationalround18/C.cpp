#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;

    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(3,-1e9));
    dp[n][0]=0;
    for(int i=n-1;i>=0;i--){
        int v=(s[i]-'0')%3;
        for(int j=0;j<3;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][(j-v+3)%3]+1);
        }
    }


    int st=-1,mx=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0') continue;
        int v=(s[i]-'0')%3;
        int need=(3-v)%3;
        if(dp[i+1][need]+1>mx){
            mx=dp[i+1][need]+1;
            st=i;
        }
    }
    if(mx<=0){
        bool ok=false;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ok=true;
                break;
            }
        }
        if(ok){
            cout<<0<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
        return;
    }

    string res="";
    res+=s[st];
    int need=(3-(s[st]-'0')%3)%3;
    int pos=st+1;
    while(pos<n){
        int v=(s[pos]-'0')%3;
        if(dp[pos][need]==dp[pos+1][(need-v+3)%3]+1){
            res+=s[pos];
            need=(need-v+3)%3;
        }
        pos++;
    }
    cout<<res<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;

}