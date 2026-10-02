#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++) cin>>a[i];
    int ans=0;
    vector<bool> vis(n+1);
    auto check=[&](int l,int r){
        while(l>=0&&r<2*n&&a[l]==a[r]){
            l--;
            r++;
        }
        l++;
        r--;
        if(l>r) return;
        for(int i=l;i<=r;i++) vis[a[i]]=1;
        int mex=0;
        while(vis[mex]) mex++;
        ans=max(ans,mex);
        for(int i=l;i<=r;i++) vis[a[i]]=0;
    };
    for(int i=0;i<2*n;i++){
        check(i,i);
        check(i,i+1);
    }
    cout<<ans<<'\n';
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