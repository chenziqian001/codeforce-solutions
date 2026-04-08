#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int x,y;
    cin>>x>>y;
    cout<<(x-y)*2<<'\n';
    for(int i=x;i>=y;i--) cout<<i<<" ";
    for(int i=y+1;i<x;i++) cout<<i<<" ";
    cout<<'\n';
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




