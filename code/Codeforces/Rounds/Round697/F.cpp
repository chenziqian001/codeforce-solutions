#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve(){
    int n;
    cin>>n;
    vector<string> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> base(n);
    for(int j=0;j<n;j++){
        base[j]=a[0][j]^b[0][j];
    }
    for(int i=1;i<n;i++){
        int diff=(a[i][0]^b[i][0])^base[0];
        for(int j=1;j<n;j++){
            if((a[i][j]^b[i][j])^base[j]!=diff){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES"<<'\n';
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