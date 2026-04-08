#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,c;
    cin>>n>>c;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x+min(i+1,n-i),x+i+1};  
    }
    sort(a.begin(),a.end());
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1].first;
    }
    int res=0;
    for(int i=0;i<n;i++){
        int nc=c-a[i].second;
        if(nc<0) continue;
        int l=0,r=n;
        int mx=0;
        while(l<=r){
            int mid=(l+r)/2;
            int val=pre[mid];
            int pos=mid+1;
            if(mid>i){
                val-=a[i].first;
                pos--;
            }
            if(val<=nc){
                mx=max(mx,pos);
                l=mid+1;
            }
            else r=mid-1;
        }

        res=max(res,mx);
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