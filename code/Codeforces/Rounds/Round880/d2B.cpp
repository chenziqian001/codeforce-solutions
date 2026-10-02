#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,g;
    cin>>n>>k>>g;
    int x=(g-1)/2;
    if(k*g<=(n-1)*x){
        cout<<k*g<<'\n';
        return;
    }
    int res=(n-1)*x;
    int v=k*g-(n-1)*x;
    int re=v%g;
    if(re<=x){
        res+=re;
    }
    else res-=(g-re);
    cout<<res<<'\n';
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