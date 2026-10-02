#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=676767677;



void solve(){
    int n;
    cin>>n;
    int a=1,b=3*n-1,c=3*n;
    for(int i=0;i<n;i++){
        cout<<a<<" "<<b<<" "<<c<<" ";
        a++;
        b-=2;
        c-=2;
    }
    cout<<'\n';
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
