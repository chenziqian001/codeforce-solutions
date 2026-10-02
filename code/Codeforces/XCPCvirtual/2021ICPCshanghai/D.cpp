#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int p,q;
    cin>>p>>q;

    if(p<q*2){
        cout<<0<<" "<<0<<'\n';
        return;
    }



    int d2=p*p-4*q*q;
    int d=sqrtl(d2);

    if(d*d==d2){
        int a=p+d,b=2*q;
        int g=__gcd(a,b);
        cout<<a/g<<" "<<b/g<<'\n';
    }
    else{
        cout<<0<<" "<<0<<'\n';
    }
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