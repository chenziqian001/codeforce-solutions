#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=2e18;


int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void solve(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    cout<<qp(2,n*m-(n-r+1)*(m-c+1))<<'\n';
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