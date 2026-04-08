#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int nx=a[n-1];
    int res=0;
    for(int i=n-2;i>=0;i--){
        int x=(a[i]+nx-1)/nx;
        res+=x-1;
        nx=a[i]/x;
    }


    cout<<res<<'\n';




}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}