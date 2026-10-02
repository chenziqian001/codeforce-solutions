#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    } 
    vector<int> v={0};
    for(auto [x,y]:mp){
        v.push_back(y);
    }

    n=v.size()-1;
    vector<int> pre(n+2);
    vector<int> suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+v[i];
    int res=inf;
    for(int i=1;i<=n;i++){
        int x=pre[i-1];
        int y=suf[i+1];
        res=min(res,max(x,y));
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