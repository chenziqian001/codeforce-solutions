#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k;
    string s,t;
    cin>>n>>k>>s>>t;
    for(int i=0;i<n;i++){
        if(i<k && i+k>=n && s[i]!=t[i]) {
            cout<<"NO"<<'\n';
            return;
        }
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
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
