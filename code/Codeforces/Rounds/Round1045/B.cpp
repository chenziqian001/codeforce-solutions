#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];



    for(int i=0;i<n;i++){
        int x=a[i];
        int rem=x%(k+1);
        a[i]=x+rem*k;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
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