#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) swap(a[i],b[i]);
    }
    int sum=accumulate(b.begin(),b.end(),0LL);

    int curmx=*max_element(a.begin(),a.end());
    int res=sum+curmx;
    for(int i=0;i<n;i++){
        res=max(res,curmx-b[i]+a[i]+max(a[i],b[i]));
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