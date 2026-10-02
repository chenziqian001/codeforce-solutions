#include<bits/stdc++.h>
using namespace std;
#define int long long
const int lim=2e18;
void solve(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<-1<<'\n';
    }
    else{
        cout<<1<<" "<<-1<<" "<<n/2<<'\n';
    }
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}