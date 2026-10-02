#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

void solve(){
    int n,k;
    cin>>n>>k;
    auto cnt1=[&](int t){return t/4+(t%4>=1);};
    auto cnt0=[&](int t){return t/4+(t%4>=3);};

    int l1=cnt1(k-1)% mod;
    int l0=(cnt0(k-1)+1) % mod;
    int r1=(cnt1(n)-cnt1(k-1)+mod)%mod;
    int r0=(cnt0(n)-cnt0(k-1)+mod)%mod;
    int res=(l0*r0%mod+l1*r1%mod)%mod;
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


