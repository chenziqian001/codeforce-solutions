#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    for(int k=0;k<=m;k++){
        vector<int> dp(k+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=k;j>=0;j--){
                if(dp[j]==-1) continue;
                int len=dp[j];
                if(len<m-k && s[i]==t[k+len]) dp[j]=max(dp[j],len+1);
                if(j<k && s[i]==t[j]) dp[j+1]=max(dp[j+1],len);
            }
        }
        if(dp[k]==m-k){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}