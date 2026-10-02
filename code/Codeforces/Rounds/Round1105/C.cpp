#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=2e18;

void solve(){
    int n;
    cin>>n;
    int tt=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        tt^=a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    if(tt==0){
        cout<<1<<'\n';
        return;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if((a[i]^tt)<=a[i]) res++;
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