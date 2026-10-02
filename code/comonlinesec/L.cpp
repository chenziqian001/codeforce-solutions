#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=a[n-i];
    }
    if(n==1){
        cout<<a[0]<<'\n';
        return;
    }
    int res=2e18;

    int s=a[0];
    int mini=1e18;
    for(int i=1;i<n;i++){
        mini=min(mini,a[i]+a[i-1]);
        int exa=n-1-i;
        int cur=s*2+a[i];
        if(cur+exa*mini<res){
            res=cur+exa*mini;
        }
        
        s+=a[i];
    }


    s=b[0];
    mini=1e18;
    for(int i=1;i<n;i++){
        mini=min(mini,b[i]+b[i-1]);
        int exa=n-1-i;
        int cur=s*2+b[i];
        if(cur+exa*mini<res){
            res=cur+exa*mini;
        }
        
        s+=b[i];
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