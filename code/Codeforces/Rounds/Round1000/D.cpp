#include<bits/stdc++.h>
using namespace std;
#define int long long


//三分查找应用题
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> prea(n+2);
    vector<int> preb(m+2);
    for(int i=1;i<=n;i++) prea[i]=prea[i-1]+a[n-i]-a[i-1];
    for(int i=1;i<=m;i++) preb[i]=preb[i-1]+b[m-i]-b[i-1];
    vector<int> ans;


    for(int x=1;2*x-m<=n-x;x++){
        int l=max(0LL,2*x-m),r=min(x,n-x);
        if(l>r) break;
        auto f=[&](int ka){return prea[ka]+preb[x-ka];};
        while(r-l>3){
            int m1=l+(r-l)/3;
            int m2=r-(r-l)/3;
            if(f(m1)<f(m2)){
                l=m1;
            }
            else r=m2;
        }
        int res=0;
        for(int i=l;i<=r;i++){
            res=max(res,f(i));
        }
        ans.push_back(res);
    }


    cout<<ans.size()<<'\n';
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  t;
    cin>>t;
    while(t--) solve();
    return 0;
}