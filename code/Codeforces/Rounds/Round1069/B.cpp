#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1);
    if(l==1){
        a[r]=a[l-1]=0;
    }
    else{
        a[r]=a[l-1]=500010;
    }
    
    int tag=1;
    for(int i=1;i<=n;i++){
        if(i==(l-1) || i==r) continue;
        else a[i]=tag++;
    }
    vector<int> res(n+1);

    for(int i=1;i<=n;i++){
        res[i]=a[i]^a[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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