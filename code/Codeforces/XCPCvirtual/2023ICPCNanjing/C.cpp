#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int p,m;
    cin>>p>>m;
    int K=m/p;
    int st=max(0LL,K-1);
    int res=st;
    for(int k=st;k<=K+2;k++){
        if(((k*p+1)^(p-1))<=m) res++;
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
 