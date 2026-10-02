#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,s,t;cin>>n>>s>>t;
    vector<int> a(n+1);
   
    for(int i=1;i<=n;i++)cin>>a[i];
    if(s==t){
        cout<<"Yes"<<'\n';
        return;
    }
    if(s>t)swap(s,t);
    if(s<=n&&t>n&&a[s]==t){
        cout<<"No\n";
        return;
    }
    if(n<=2&&(s<=n)==(t<=n)){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}