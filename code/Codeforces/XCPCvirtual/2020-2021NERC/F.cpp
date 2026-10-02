#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int> a(4);
    for(int i=0;i<4;i++) cin>>a[i];
    sort(a.begin(),a.end());
    cout<<min(a[0],a[1])*min(a[2],a[3])<<'\n';
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