#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=9e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int pos=0;
    for(int i=2;i<n;i++){
        if(a[i]<a[i-1] && a[i]<a[i+1]){
            pos=i;
            break;
        }
    }
    vector<int> pre(n+1);
    vector<int> suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
    double res=0;
    for(int i=pos+1;i<=n;i++){
        res=max(res,(double)pre[i]/i);
    }
    for(int i=pos-1;i>=1;i--){
        res=max(res,(double)suf[i]/(n-i+1));
    }
    cout<<fixed<<setprecision(20);
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

