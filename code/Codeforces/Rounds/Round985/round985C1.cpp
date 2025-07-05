#include<bits/stdc++.h>
using namespace std;

int f(int a,int x){
    return a+(a<x)-(a>x);
}



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int dp[3]={0,-n,-n};
    for(int x:a){
        int n0=f(dp[0],x);
        int n1=max(dp[0],dp[1]);
        int n2=max(f(dp[1],x),f(dp[2],x));
        dp[0]=n0;
        dp[1]=n1;
        dp[2]=n2;
    
    }
    cout<<max(dp[1],dp[2])<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}