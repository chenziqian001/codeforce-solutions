#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x,k;
    cin>>x>>k;
    if(x<k){
        cout<<1<<'\n';
        cout<<x<<'\n';
        return;
    }
    int dis=x;
    if(dis%k){
        cout<<1<<'\n';
        cout<<x<<'\n';
        return;
    }
    cout<<2<<'\n';
    while(dis%k==0){
        dis--;
    }
    cout<<dis<<" "<<x-dis<<'\n';




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