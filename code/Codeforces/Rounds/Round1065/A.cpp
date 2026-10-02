#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;

    int res=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if((i*2+j*4)==n) res++;
        }
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