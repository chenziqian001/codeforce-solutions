#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 

void solve(){
    int x;
    cin >> x;
    if(x%2!=0||(x&(x/2))!=0) {
        cout<<-1<<'\n';
    } else {
        cout<<(x|(x/2))<<" "<<(x/2)<<'\n';
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