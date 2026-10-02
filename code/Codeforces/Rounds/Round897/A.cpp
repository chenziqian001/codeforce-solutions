#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),[&](int x,int y){
        return a[x]<a[y];
    });

    vector<int> b(n);
    int val=n;
    for(int i=0;i<n;i++){
        b[p[i]]=val--;
    }
    for(int x:b){
        cout<<x<<" ";
    }
    cout<<'\n';

    

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}

