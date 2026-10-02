#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cnt=0;
    int res=0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]==1);
        if(a[i]>1){
            res+=a[i];
        }
    }
    if(cnt && a[n-1]==1){
        res++;
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