#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    bool w=false;
    for(int i=0;i<n;i+=2){
        int d=a[i]-(i+1<n?a[i+1]:0);
        if(d%2!=0){
            w=true;
            break;
        }
    }
    if(w) cout<<"Insight"<<'\n';
    else cout<<"Maya"<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}