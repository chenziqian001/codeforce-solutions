#include<bits/stdc++.h>
using namespace std;
#define int long long

    
void solve(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;


    for(int i=1;i<=n;i++){
        if(x*i+y*i>=n){
            cout<<i<<'\n';
            return;
        }
        if(i>=z){
            if(x*i+10*y*(i-z)>=n){
                cout<<i<<'\n';
                return;
            }
        }
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