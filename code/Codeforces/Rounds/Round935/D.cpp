#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) c[i]=min(a[i],b[i]);


    int res=inf;
    int suf=0;
    for(int i=n;i>=1;i--){
        if(i<=m){
            res=min(res,suf+a[i]);
        }
        suf+=c[i];
    }
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}