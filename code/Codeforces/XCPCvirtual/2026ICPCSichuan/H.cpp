#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int s0=0,s1=0;
    for(int x:a){
        int c=__builtin_popcount(x);
        if(c%2==0) s0+=x;
        else s1+=x;
    }
    cout<<max(s1,s0)<<'\n';
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

