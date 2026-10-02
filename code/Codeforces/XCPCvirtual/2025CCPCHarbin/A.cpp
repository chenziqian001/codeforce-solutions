#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int d=0;
    for(int i=1;i<n;i++){
        d=__gcd(d,abs(a[i]-a[0]));
    }
    if(d==0){
        cout<<"infinite"<<'\n';
        return;
    }
    int g=__gcd(d,a[0]);
    cout<<d<<" "<<d/g<<'\n';
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