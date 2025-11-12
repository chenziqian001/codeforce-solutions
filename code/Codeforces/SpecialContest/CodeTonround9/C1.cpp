#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;


void solve(){
    int x,m;
    cin>>x>>m;
    int res=0;
    for(int y=1;y<=min(x*2,m);y++){
        if(y==x) continue;
        if(y%(x^y)==0 || x%(x^y)==0) res++;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}