#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    bool ok=false;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==67){
           ok=true;
        }
    }
    if(ok)  cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

     
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
