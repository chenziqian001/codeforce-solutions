#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int a,b;
    cin>>a>>b;
    if(a%2==0) swap(a,b);
    if(a>b) cout<<1<<'\n';
    else cout<<2<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}