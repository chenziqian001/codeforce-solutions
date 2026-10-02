#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    if(a[0]==a[n-1]){
        cout<<"NO"<<'\n';
        return;
    }
    else{
        cout<<"YES"<<'\n';
        cout<<a[0]<<" "<<a[n-1]<<" ";
    }
    for(int i=1;i<n-1;i++){
        cout<<a[i]<<" ";
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
 