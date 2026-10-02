#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    
    int mn=2e9,i1=0,i2=0,v=0;
    for(int i=0;i<n-1;i++){
        int cur=a[i].first^a[i+1].first;
        if(cur<mn){
            mn=cur;
            i1=a[i].second;
            i2=a[i+1].second;
            v=a[i].first;
        }
    }
    
    int x=((1<<k)-1)^v;
    cout<<i1<<" "<<i2<<" "<<x<<'\n';
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

