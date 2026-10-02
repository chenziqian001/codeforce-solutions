#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int dp0=0,dp1=0;
    for(int i=0;i<n;i++){
        if(s[i]=='2')dp0++;
        else if(s[i]=='1'||s[i]=='3')dp1=max(dp1+1,dp0+1);
    }
    cout<<n-max(dp0,dp1)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}