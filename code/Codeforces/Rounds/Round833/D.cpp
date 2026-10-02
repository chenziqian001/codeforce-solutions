#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int a,b,d;
    cin>>a>>b>>d;
    int c = a|b;

    if(__builtin_ctzll(c)<__builtin_ctzll(d)){
        cout<<-1<<'\n';
        return;
    }
    int x=0;
    int tz=__builtin_ctzll(d);
    for(int i=0;i<30;i++){
        if(c>>i&1){
            if(!(x>>i&1)) x+=(d<<(i-tz));
        }
    }
    cout<<x<<'\n';
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