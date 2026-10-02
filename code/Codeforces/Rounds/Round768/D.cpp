#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int g=0;
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        g=__gcd(g,x);
    }

    vector<int> c(g),sum(g),mn(g,1e18);
    for(int i=0;i<n;i++){
        int gp=i%g;
        if(a[i]<0) c[gp]^=1;
        sum[gp]+=abs(a[i]);
        mn[gp]=min(mn[gp],abs(a[i]));
    }
    int s0=0,s1=0;
    for(int i=0;i<g;i++){
        s0+=(c[i]==0?sum[i]:sum[i]-2*mn[i]);
        s1+=(c[i]==1?sum[i]:sum[i]-2*mn[i]);
    }
    cout<<max(s0,s1)<<'\n';


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