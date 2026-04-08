#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int g=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(i){
            g=__gcd(g,a[i]-a[0]);
            sum+=abs(a[i]-a[i-1]);
        }
    }


    int res=a[0]-1;
    if(g) res%=2*g;
    cout<<res+1+sum<<'\n';


}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}