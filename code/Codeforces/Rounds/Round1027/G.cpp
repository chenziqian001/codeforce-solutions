#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        int p=a[i];
        while(p%2==0){
            p/=2;
            b[i]++;
        }
        c[i]=p;
    }
    vector<int> pre(n+1);
    vector<int> suf(n+2);
    for(int i=1;i<n;i++){
        if(a[i]<a[i+1]) pre[i]=pre[i-1]+(1LL<<b[i]);
        else{
            int p=a[i];
            while(p%2==0 && p>a[i+1]){
                p/=2;
            }
            if(a[i+1]==p){
                int np=a[i]-p*2;
                pre[i]=pre[i-1]+1+np/c[i];
            }
            else pre[i]=pre[i-1]+(1LL<<b[i]);
        } 
    }
    for(int i=n;i>1;i--){
        if(a[i]<a[i-1]) suf[i]=suf[i+1]+(1LL<<b[i]);
        else{
            int p=a[i];
            while(p%2==0 && p>a[i-1]){
                p/=2;
            }
            if(a[i-1]==p){
                int np=a[i]-2*p;
                suf[i]=suf[i+1]+1LL+np/c[i];
            }
            else suf[i]=suf[i+1]+(1LL<<b[i]);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res=max(res,pre[i-1]+(1LL<<b[i])+suf[i+1]);
    }
    if(res>=k){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}