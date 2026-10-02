#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,x1,x2,k;
    cin>>n>>x1>>x2>>k;
    if(n<=3){
        cout<<1<<'\n';
        return;
    }
    cout<<min(abs(x1-x2),abs(n-abs(x1-x2)))+k<<'\n';

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