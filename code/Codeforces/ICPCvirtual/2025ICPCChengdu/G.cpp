#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,m;
    cin>>n>>k>>m;

    int tt=n/k-1;
    int use=tt/2;


    int remain=n-n/k;

    int more=m-remain;
    if(more<0){
        cout<<1+use+m<<'\n';
    }
    else{
        cout<<min(n,1+m+max(0LL,(tt-more)/2))<<'\n';

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