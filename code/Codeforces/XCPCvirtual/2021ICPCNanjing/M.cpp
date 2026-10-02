#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<a[0]<<'\n';
        return;
    }
    int base= 0;
    for(int x:a) base+=abs(x);
    sort(a.begin(),a.end());
    if(a.back()<0){
        cout<<base-2*abs(a[n-1])<<'\n';
    }
    else if(*a.begin()>=0){
        cout<<base-2*a[0]<<'\n';
    }
    else{
        cout<<base<<'\n';
    }
    



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
