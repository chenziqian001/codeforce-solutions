#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    int cl=0,cr=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<r) cl++;
        if(a[i]>l) cr++; 
    }
    sort(a.begin(),a.end());
    vector<int> pre(n+1);
    vector<int> suf(n+2);
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    for(int i=0;i<n;i++) suf[i+1]=suf[i]+a[n-i-1];
    int res=-1e18;
    for(int x=0;x<=n;x++){
        int y=min({x,n-x,cr});
        res=max(res,x*l-y*l-pre[x]+suf[y]);
    }
    for(int y=0;y<=n;y++){
        int x=min({y-1,n-y,cl});
        if(x>=0) res=max(res,x*r-y*r-pre[x]+suf[y]);
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