#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            int res=a[i-1]/(a[i]-1);
            cout<<res<<'\n';
            return;
        }
    }
    int d=a[1]-a[0];
    cout<<max(d,a[n-1]/d)<<'\n';
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