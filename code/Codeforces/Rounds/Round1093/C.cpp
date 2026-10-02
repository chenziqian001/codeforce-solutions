#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int p,q;
    cin>>p>>q;
    int s=2*p+4*q+1;
    for(int a=3;a*a<=s;a+=2){
        if(s%a==0){
            int b=s/a;
            int n=(a-1)/2;
            int m=(b-1)/2;
            int d=n>m?n-m:m-n;
            if(q<=min(n*(m+1),m*(n+1))){
                cout<<n<<" "<<m<<'\n';
                return;
            }
        }
    }
    cout<<-1<<'\n';
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