#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int w,h,d,n;
    cin>>w>>h>>d>>n;
    int x=__gcd(n,w);
    n/=x;
    int y=__gcd(n,h);
    n/=y;
    int z=__gcd(n,d);
    n/=z;
    if(n==1){
        cout<<x-1<<" "<<y-1<<" "<<z-1<<'\n';
    }else{
        cout<<-1<<'\n';
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}