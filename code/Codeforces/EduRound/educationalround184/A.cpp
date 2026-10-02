#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,a;
    cin>>n>>a;
    int c1=0,c2=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<a)c1++;
        if(x>a)c2++;
    }
    if(c1>c2)cout<<a-1<<"\n";
    else cout<<a+1<<"\n";

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