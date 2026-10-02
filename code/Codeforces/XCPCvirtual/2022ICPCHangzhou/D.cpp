#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0LL);
    cout<<fixed<<setprecision(10);
    cout<<2.0*sum/(n+1)<<" ";
    for(int i=1;i<n;i++){
        cout<<1.0*sum/(n+1)<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}