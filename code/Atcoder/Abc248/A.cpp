#include<bits/stdc++.h>
using namespace std;


void solve(){
    int s,a,b,x;
    cin>>s>>a>>b>>x;
    int cnt=x/(a+b);
    int tt=cnt*a;
    int rem=x%(a+b);
    tt+=min(rem,a);
    cout<<tt*s<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
}