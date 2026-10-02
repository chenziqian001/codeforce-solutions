#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int s=0;
    for(int i=0;i<n-1;i++) s+=abs(a[i+1]-a[i]);
    int res=s;
    for(int i=0;i<n;i++){
        int cur=s;
        if(i>0 && i<n-1) cur=s-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);
        else if(i==0) cur=s-abs(a[1]-a[0]);
        else if(i==n-1) cur=s-abs(a[n-1]-a[n-2]);
        res=min(res,cur);
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

