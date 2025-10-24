#include<bits/stdc++.h>
using namespace std;


 
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<long long> dp(n+5,0);
    long long res=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            dp[i]=dp[i+1];
        }
        else{
            dp[i]=n-i+dp[i+3];
        }
        res+=dp[i];
    }
    
    cout<<res<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
