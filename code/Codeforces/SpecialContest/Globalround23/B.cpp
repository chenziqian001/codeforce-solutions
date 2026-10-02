#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    int l=0,r=n-1;
    
    while(l<=r){
        while(a[r]!=0 && r>=0) r--;
        while(a[l]!=1 && l<n) l++;
        if(r<0 || l>=n || l>=r) break;
        res++;
        r--;
        l++;
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
