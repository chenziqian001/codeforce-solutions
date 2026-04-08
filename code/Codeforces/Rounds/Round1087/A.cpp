#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,c,k;
    cin>>n>>c>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]>c) break;
        else{
            int add=min(k,c-a[i]);
            c+=a[i]+add;
            k-=add;
        }
    }
    cout<<c<<'\n';

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
