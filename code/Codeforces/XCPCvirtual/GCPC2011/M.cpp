#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    double d,s,e;
    cin>>d>>s>>e;
    if(s<=d-s-e)printf("%.9lf\n",s*(d-s)/(d*(d-s-e)));
    else printf("%.9lf\n",(s+e)/d);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}