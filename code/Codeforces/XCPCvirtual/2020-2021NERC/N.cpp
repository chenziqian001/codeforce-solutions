#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int c1,c2,c3;
    cin>>c1>>c2>>c3;
    int a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;

    c1-=a1;
    c2-=a2;
    c3-=a3;
    if(c1<0 || c2<0 || c3<0){
        cout<<"NO"<<'\n';
        return;
    }  
    a4-=min(a4,c1);
    a5-=min(a5,c2);

    if(a4+a5>c3){
        cout<<"NO"<<'\n';
    }
    else cout<<"YES"<<'\n';

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