#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int l=1,r=n;
    for(int i = 0; i < k; ++i) {
        for(int j = i; j < n; j += k) {
            if(i % 2 == 0) {
                a[j] = l++;
            } else {
                a[j] = r--;
            }
        }
    }
    for (int x:a) cout<<x<<" ";
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