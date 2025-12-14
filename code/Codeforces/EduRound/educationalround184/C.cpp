#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0LL);
    vector<int> b=a;
    for(int i=0;i<n;i++){
        b[i]=(i+1)*2-a[i];
    }

    int cur=0;
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,cur);
        cur=max(cur+b[i],b[i]);
    }
    mx=max(mx,cur);
    
    cout<<sum+mx<<'\n';

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