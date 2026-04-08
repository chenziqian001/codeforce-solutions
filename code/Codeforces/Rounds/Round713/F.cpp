#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,c;
    cin>>n>>c;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n-1;i++) cin>>b[i];
    b[n-1]=114514939288;

    int res=1e18;
    int cur=0;
    int re=0;

    for(int i=0;i<n;i++){
        res=min(res,cur+max(0LL,(c-re+a[i]-1)/a[i]));
        int newd=max(0LL,(b[i]-re+a[i]-1)/a[i]);
        cur+=newd+1;
        re+=newd*a[i]-b[i];
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