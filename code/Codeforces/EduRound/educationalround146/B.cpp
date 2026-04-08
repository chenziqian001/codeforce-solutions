#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int a,b;
    cin>>a>>b;

    int res=2e9;
    for(int i=1;i<=1e5;i++){
        res=min(res,i+1+(a-1)/i+(b-1)/i);
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}