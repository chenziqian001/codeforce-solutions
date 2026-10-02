#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(k+1);
    for(int i=1;i<=k;i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];


    vector<int> res;
    for(int i=k;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(b[j]==i){
                while(b[j]!=k+1){
                    b[j]++;
                    res.push_back(j);
                }
            }
        }
    }
    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x<<" ";
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