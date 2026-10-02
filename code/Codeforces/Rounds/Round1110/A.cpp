#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n<2*k){
        cout<<-1<<'\n';
        return;
    }
    int ans=0;
    for(int i=0;i<k;i++){
        if(s[i]=='L')ans++;
    }
    for(int i=n-k;i<n;i++){
        if(s[i]=='R')ans++;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}