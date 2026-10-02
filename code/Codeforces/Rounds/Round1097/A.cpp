#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int i=n-1;i>=0;i--){
        int val=(i==n-1?0:a[i+1]);
        if(val>0){
            a[i]+=val;
        }
        if(a[i]>0) res++; 
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