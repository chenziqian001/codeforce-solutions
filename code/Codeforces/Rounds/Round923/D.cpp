#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> p(n+1,-1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]) p[i]=i-1;
        else p[i]=p[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(p[r]>=l){
            cout<<p[r]<<" "<<r<<'\n';
        }
        else cout<<-1<<" "<<-1<<'\n';
    }
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