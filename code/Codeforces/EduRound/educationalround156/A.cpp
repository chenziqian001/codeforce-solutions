#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    int n;
    cin>>n;
    for(int x=1;x<=n-2;x++){
        if(x%3==0) continue;
        for(int y=1;y<=n-x-1;y++){
            if(y==x || y%3==0 || x+y>=n-1) continue;
            int z=n-x-y;
            if(z%3==0 || z==x  || z==y) continue;
            cout<<"YES"<<'\n';
            cout<<x<<" "<<y<<" "<<z<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';

    
   
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