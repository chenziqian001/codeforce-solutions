#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9+10;

void solve(){
    int n;
    cin>>n;
    
    vector<int> f(n);
    for(int i=0;i<n;i++) cin>>f[i];
    vector<int> a(n);


    for(int i=1;i<n-1;i++){
        a[i]=(f[i-1]+f[i+1]-2*f[i])/2;
    }

    int g1=f[0];
    int gn=f[n-1];

    for(int i=1;i<n-1;i++){
        g1-=a[i]*i;
        gn-=a[i]*(n-1-i);
    }

    a[n-1]=g1/(n-1);
    a[0]=gn/(n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<'\n';

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
