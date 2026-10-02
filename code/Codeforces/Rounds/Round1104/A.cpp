#include<bits/stdc++.h>
using namespace std;
#define int long long


const int inf=2e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=n-1;i>=0;i--){
        int x=a[i];
        for(int j=i;j<n;j++){
            a[j]=min(a[j],x);
        }
    }

    int res=accumulate(a.begin(),a.end(),0LL);
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