#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0LL);
    int res=0;

    for(int i= 60 ; i >= 0 ; i--){
        __int128 mx=(__int128)n*((1LL<<i)-1);
        if(sum>mx){
            res|=(1LL<<i);
            sum-=min(n,sum>>i)*(1LL<<i);
        }
    }
    cout<<res<<'\n';
}
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
 
 