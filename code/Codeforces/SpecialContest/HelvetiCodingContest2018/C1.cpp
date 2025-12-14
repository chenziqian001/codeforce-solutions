#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=(a[i-1]+x)%p;
    }
    int res=0;
    for(int i=1;i<n;i++){
        res=max(res,a[i]%p+(a[n]-a[i]+p)%p);
    }
    cout<<res<<'\n';

    //system("pause");
    return 0;

}