#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> pre(n);
    vector<int> suf(n);
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+ (a[i]>=a[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]+(a[i]>=a[i+1]);
    }

    int res=suf[0];


    for(int pos=0;pos<n-1;pos++){
        res=min(res,pre[pos]+1+suf[pos+1]);
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