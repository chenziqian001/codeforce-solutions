#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int> g(n);
    for(int i=0;i<n-1;i++){
        g[i]=__gcd(a[i],a[i+1]);
    }
    int res=0;

    if(a[0]>g[0]) res++;
    if(a[n-1]>g[n-2]) res++;
    for(int i=1;i<n-1;i++){
        if(a[i]>lcm(g[i-1],g[i])) res++;
    }
    cout<<res<<'\n';
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

