#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1"<<'\n';
        return;
    }
    if(n==2){
        cout<<"-1"<<'\n';
        return;
    }
    vector<int> a(n);
    a[0]=1;
    a[1]=2;
    a[2]=3;
    int s=6;
    for(int i=3;i<n;i++){
        a[i]=s;
        s*=2;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}