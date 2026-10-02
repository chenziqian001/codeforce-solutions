#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<2*(max(abs(x1-x2)+1,2LL)+max(abs(y1-y2)+1,2LL))<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}