#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    int g=0;
    for(int i=1;i<n;i++){
        if(!g){
            g=a[i]-a[i-1];
        }
        else g=__gcd(g,a[i]-a[i-1]);
    }


    for(int i=0;i<m;i++){
        int ng=__gcd(g,a[0]+b[i]);
        cout<<ng<<" ";
    }
    cout<<'\n';





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