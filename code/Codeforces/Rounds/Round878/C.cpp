#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k,q;
    cin>>n>>k>>q;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    int tmp=0;
    for(int x:a){
        tmp=x<=q?tmp+1:0;
        res+=max(0LL,tmp-k+1);
    }

    cout<<res<<'\n';

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