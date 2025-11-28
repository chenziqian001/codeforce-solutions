#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<int> pa(n+1);
    vector<int> pb(m+1);

    for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[i-1];
    for(int i=1;i<=m;i++) pb[i]=pb[i-1]+b[i-1];

    int res=0;
    for(int i=0;i<=n;i++){
        int a1=pa[i];
        int a2=pa[n]-pa[i];

        int b1=pb[m]-pb[m-i];
        int b2=pb[n-i];

        res=max(res,b1-a1+a2-b2);


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



