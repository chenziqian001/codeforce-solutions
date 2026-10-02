#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=n-1;
    while(l<n && s[l]=='W') l++;
    while(r>=0 && s[r]=='W') r--;
    cout<<r-l+1<<'\n';
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