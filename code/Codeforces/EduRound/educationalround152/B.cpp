#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    stable_sort(p.begin(), p.end(),[&](int i,int j) {
        return (a[i]-1)%k>(a[j]-1)%k;
    });
    for(int i=0;i<n;i++) {
        cout<<p[i]+1<<" ";
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