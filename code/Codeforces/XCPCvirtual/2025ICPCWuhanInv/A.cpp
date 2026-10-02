#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,pair<int,int>> mp;
    bool ok=false;
    while(q--){
        int p,l,r;
        cin>>p>>l>>r;
        if(mp.find(p)==mp.end()) mp[p]={l,r};
        else{
            l=max(mp[p].first,l);
            r=min(mp[p].second,r);
            if(l>r){
                ok=true;
            }
            mp[p]={l,r};
        }
    }
    if(ok){
        cout<<-1<<'\n';
        return;
    }

 
    int res=0;
    for(auto [pos,ran]:mp){
        int val=a[pos];
        if(val>=ran.first && val<=ran.second) continue;
        else{
            res+=min(abs(val-ran.first),abs(val-ran.second));
        }
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
 
 