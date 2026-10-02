#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

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
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=i*20+x;
    } 
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b[i]=i*20+x;
    } 
    int res=0;
    for(int i=0;i<n;i++){
        int c1=qp(2,n-i-1);
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        int c2=qp(2,m-k);
        int c=c1*c2%mod;
        res=(res+c)%mod;

    }
    cout<<res<<'\n';


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

