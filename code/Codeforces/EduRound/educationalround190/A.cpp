#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a*3<=b){
        cout<<(a*n)<<'\n';
    }
    else{
        cout<<(b*(n/3)+min(a*(n%3),b))<<'\n';
    }
    
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