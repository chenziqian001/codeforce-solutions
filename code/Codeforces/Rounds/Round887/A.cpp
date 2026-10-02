#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int x=1,j=0;
    for(int i=0;i<k;i++) {
        while(j<n&&a[j]-(j+1)<=x-1) {
            j++;
        }
        x+=j;
    }
    cout<<x<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}