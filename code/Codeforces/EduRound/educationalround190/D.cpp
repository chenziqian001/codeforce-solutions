#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> na(n+2,n);
    vector<int> nb(n+2,n);
    vector<int> f(n+2,n);
    int res=0;
    for(int i=n-1;i>=0;i--){
        na[a[i]]=i;nb[b[i]]=i;
        if(a[i]==b[i]){
            int nx=a[i]+1;
            if(na[nx]==nb[nx]){
                f[i]=f[na[nx]];
            }
            else f[i]=min(na[nx],nb[nx]);
        }
        if(na[1]!=nb[1]){
            res+=min(na[1],nb[1])-i;
        }
        else res+=f[na[1]]-i;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}