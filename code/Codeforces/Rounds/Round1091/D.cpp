#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> p(k+2);
    for(int i=1;i<=k;i++) cin>>p[i];
    a[0]=a[n+1]=a[p[1]];
    p[k+1]=n+1;
    int s=0;
    int mx=0;
    for(int i=0;i<=k;i++){
        int cnt=0;
        for(int j=p[i];j<p[i+1];j++){
            if(a[j]!=a[j+1]){
                cnt++;
            }
        }
        s+=cnt;
        mx=max(mx,cnt);
    }
    
    cout<<max(mx,s/2)<<'\n';


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