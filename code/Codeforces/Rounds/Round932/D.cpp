#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int tt=(c+1)*(c+2)/2;
    int even=0;
    int odd=0;
    for(int x:a){
        tt=tt-(x/2+1+c-x+1);
        even+=(x%2==0);
        odd+=(x%2==1);
    }
    tt+=(even+1)*even/2+odd*(odd+1)/2;
    cout<<tt<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}


