#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    int od=n/3*2+n%3;
    cout<<n*(n-1)/2-od*(od-1)/2<<'\n';
}   



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}


