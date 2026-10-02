#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=676767677;



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            res=max(res,a[i]^a[j]);
        }
    }
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