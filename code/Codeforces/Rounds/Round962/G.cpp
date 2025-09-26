#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);

    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        long long x=rng();
        v[l-1]^=x;
        v[r-1]^=x;
    }


    map<int,int> mp;
    int mx=0;
    long long pre=0;
    for(int val:v){
        mx=max(mx,mp[pre^=val]++);
    }
    cout<<n-mx-1<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}