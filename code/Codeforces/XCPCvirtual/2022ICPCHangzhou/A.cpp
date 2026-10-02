#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int A1=accumulate(a.begin(),a.end(),0LL)%m;
    int A2=(A1+(n+1)*n/2)%m;
    int g=__gcd(n,m);
    int k0=A1%g,k1=A2%g;
    int d = k0<=k1?0:1;
    int k=d?k1:k0;
    int v=(d?A2:A1)-k;
    int s=0;
    for(int y=0;y<=n;y++){
        int c=m*y-v;
        if(c>=0 && c%n==0){
            s=(c/n)%m;
            break;
        }
    }
    cout<<k<<'\n';
    cout<<s<<" "<<d<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}