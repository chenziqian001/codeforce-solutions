#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,m;
    cin>>n>>m;
    if(__gcd(n,m)!=1){
        cout<<"No"<<'\n';
        return;
    }
    else {
        cout<<"Yes"<<'\n';
    }
    for(int i=0;i<n;i++){
        cout<<(1+i*m)%(n*m)<<" ";
    }
    cout<<'\n';
    for(int i=0;i<m;i++){
        cout<<(1+i*n)%(n*m)<<" ";
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
 
 