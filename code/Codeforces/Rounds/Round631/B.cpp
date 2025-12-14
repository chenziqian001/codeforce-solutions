#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int d,m;
    cin>>d>>m;
    int res=1;


    for(int i=0;i<30;i++){
        if(d<(1<<i)) break;
        res=res*(min(d,(1LL<<(i+1))-1)-(1LL<<i)+2+m)%m;
    }
    res--;
    if(res<0) res=(res+m)%m;

    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}