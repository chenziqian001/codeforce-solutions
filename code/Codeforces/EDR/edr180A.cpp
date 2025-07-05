#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,x,y;
    cin>>a>>x>>y;
    if(x>y) swap(x,y);
    if(a>=x&&a<=y) cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}