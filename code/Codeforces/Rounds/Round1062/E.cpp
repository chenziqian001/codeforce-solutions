#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    a.push_back(-1e9);
    a.push_back(1e9);
    n+=2;
    sort(a.begin(),a.end());
    int l=0,r=x+1;
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        a[0]=-mid,a[n-1]=x+mid;
        int s=0;
        for(int i=1;i<n;i++){
           s+=max(0LL,(a[i]-mid)-(a[i-1]+mid)+1);
        }
        if(s>=k){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    a[0]=-res;a[n-1]=x+res;
    int j=0;
    for(int i=1;i<n;i++){
       for(j=max(j,a[i-1]+res);j<=min((a[i]-res),x)&&k;j++)
    		cout<<j<<' ',k--;
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