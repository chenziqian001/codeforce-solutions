#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> suf_neg(n+1);
    for(int i=n-1;i>=0;i--){
        suf_neg[i]=suf_neg[i+1];
        if(a[i]>0) continue;
        suf_neg[i]-=a[i];
    }
    int pre=0;
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,pre+suf_neg[i]);
        if(a[i]>0) pre+=a[i];
    }
    res=max(res,pre);

    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}