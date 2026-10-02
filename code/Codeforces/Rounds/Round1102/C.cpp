#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++){
        vector<int> v(n);
        int mx=0;
        for(int j=1;j<n;j++){
            mx=max(mx,a[(i-j+n)%n]);
            v[(i-j+n)%n]=mx;
        }
        int res=0;
        mx=0;
        for(int d=1;d<n;d++){
            mx=max(mx,a[(i+d-1)%n]);
            res+=min(v[(i+d)%n],mx);
        }
        cout<<res<<" ";
    }
    cout<<'\n';




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