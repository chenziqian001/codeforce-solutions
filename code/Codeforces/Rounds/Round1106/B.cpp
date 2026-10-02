#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=2e18;

void solve(){
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++){
        res+=(n/i)*(n/i);
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
    return 0;
}