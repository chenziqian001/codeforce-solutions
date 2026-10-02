#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<1700) res++;
    }
    cout<<res<<'\n';
    

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