#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int mxl=0;
    int mir=1e9+10;
    int res=0;

    for(int i=0;i<n;i++){
        res+=abs(a[i]-b[i]);
        int l=min(a[i],b[i]);
        int r=max(a[i],b[i]);
        mxl=max(mxl,l);
        mir=min(mir,r);
    }

    res+=max(0LL,2*(mxl-mir));
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