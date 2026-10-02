#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]==-1) a[0]=a[n-1];
    if(a[n-1]==-1) a[n-1]=a[0];
    for(int i=0;i<n;i++){
        if(a[i]==-1) a[i]=0;
    }
    cout<<abs(a[n-1]-a[0])<<'\n';
    for(int x:a) cout<<x<<" ";
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