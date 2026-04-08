#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
   

    vector<int> f={0,0,0};


    for(int i=0;i<n;i++){
        int v;
        cin>>v;

        f[2]=max(f[2],f[1]+v-i);
        f[1]=max(f[1],f[0]+v);
        f[0]=max(f[0],v+i);
    }

    cout<<f[2]<<'\n';
    

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}