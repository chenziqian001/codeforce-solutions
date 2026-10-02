#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
   
    vector<int> res;
    int mul=1;
    for(int i=n;i>=1;i--){
        if(a[i]*mul>0){
            res.push_back(i);
            mul*=-1;
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