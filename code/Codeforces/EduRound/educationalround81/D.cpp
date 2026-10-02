#include<bits/stdc++.h>
using namespace std;
#define int long long


int get(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            res-=res/i;
        }
    }
    if(n>1) res-=res/n;
    return res;
}



void solve(){
    int a,b;
    cin>>a>>b;
    int g=__gcd(a,b);
    cout<<get(b/g)<<'\n';
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

