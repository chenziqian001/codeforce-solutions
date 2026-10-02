#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    bool ok=true;;
    for(int i=1;i<n;i++){
        int x=abs(a[i]-a[i-1]);
        if(x!=5 && x!=7){
            ok=false;
        }
    }
    if(!ok){
        cout<<"NO"<<'\n';
    }
    else cout<<"YES"<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}