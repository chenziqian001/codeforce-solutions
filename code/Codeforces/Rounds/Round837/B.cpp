#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 

void solve(){
    int n,s,r;
    cin>>n>>s>>r;
    int mx=s-r;

    cout<<mx<<" ";
    int x=r/(n-1);
    int re=r%(n-1);
    
    while(re){
        cout<<x+1<<" ";
        re--;
        r-=(x+1);
    }
    while(r){
        cout<<x<<" ";
        r-=x;
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