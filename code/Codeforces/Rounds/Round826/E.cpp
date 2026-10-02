#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> f(n+1);
    f[0]=1;
    for(int i=1;i<=n;i++){
        int x=b[i];
        if(i+x<=n){
            if(f[i-1]==1) f[i+x]=1;
        }
        if(i-x>=1){
            if(f[i-x-1]==1){
                f[i]=1;
            }
        }
    }
    if(f[n]){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

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