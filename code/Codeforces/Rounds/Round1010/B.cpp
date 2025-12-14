#include<bits/stdc++.h>
using namespace std;
#define int long long


int up(int x,int n){
    while(n--){
        if(x<=1) return x;
        x=(x+1)>>1;
    }
    return x;
}

int down(int x,int n){
    while(n--){
        if(!x) return x;
        x>>=1;
    }
    return x;
}


void solve(){
    int x,n,m;
    cin>>x>>n>>m;

    cout<<down(up(x,m),n)<<" "<<up(down(x,n),m)<<'\n';
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

