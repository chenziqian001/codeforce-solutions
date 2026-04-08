#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+2),b(n+2),pre(n+2),suf(n+2);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];


    int mx=-2e18;
    int cur=0;
    for(int i=1;i<=n;i++){
        cur=max(a[i],cur+a[i]);
        pre[i]=cur;
        mx=max(mx,cur);
    }

    cur=0;
    for(int i=n;i>=1;i--){
        cur=max(a[i],cur+a[i]);
        suf[i]=cur;
    }

    if(k%2==0){
        cout<<mx<<'\n';
        return;
    }
    int res=mx;
    for(int i=1;i<=n;i++){
        res=max(res,pre[i]+suf[i]-a[i]+b[i]);
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

