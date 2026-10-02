#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    int x=inf,y=inf,z=inf;
    for(int i=0;i<n;i++){
        vector<int> tmp(3);
        for(int j=0;j<3;j++) cin>>tmp[j];
        sort(tmp.begin(),tmp.end());
        x=min(x,tmp[0]);
        y=min(y,tmp[1]);
        z=min(z,tmp[2]);
    }
    cout<<x*y*z<<'\n';


    

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