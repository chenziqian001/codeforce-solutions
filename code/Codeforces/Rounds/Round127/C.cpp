#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<n;i++) cin>>a[i];
    vector<int> l(n+1);
    vector<int> r(n+1);
    for(int i=1;i<=n;i++){
        if(a[i-1]>1){
            l[i]=l[i-1]+a[i-1]/2*2;
        }
    }
    for(int i=n;i>=1;i--){
        if(a[i]>1){
            r[i]=r[i+1]+a[i]/2*2;
        }
    }
    
    for(int i=1;i<n;i++){
        if(a[i]%2==0){
            a[i]--;
        }
        a[i]+=a[i-1];
    }


    int res=0;
    int mx=0;
    
    for(int i=1;i<=n;i++){
        mx=max(l[i]-a[i-1],mx);
        res=max(res,mx+r[i]+a[i-1]);
    }
    cout<<res<<'\n';
    //system("pause");

}


 