#include<bits/stdc++.h>
using namespace std;
#define int long long

    
void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cout<<i<< " ";
    for(int i=1;i<=n;i++) cout<<i<< " ";
    cout<<n<<" ";
    for(int i=1;i<n;i++) cout<<i<<" ";
    for(int i=1;i<=n;i++) cout<<i<< " ";
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

