#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        pre[i]=(i>=1?pre[i-1]:0)+a[i]-b[i];
    }
    vector<int> c(n,1);
    auto fuck=[&](int l,int r){
        if(l>r){
            return pre[r]+pre[n-1]-pre[l-1];
        }
        else return pre[r]-(l>=1?pre[l-1]:0);
    };
    for(int i=n-1;i>=0;i--){
        int len=1;
        while(fuck(i,(i+len-1)%n)>0){
            len+=c[(i+len)%n];
        }
        c[i]=len;
    }
    int mx=1;
    for(int i=0;i<n;i++) mx=max(mx,c[i]);
    cout<<mx<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}