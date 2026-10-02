#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long



int dfs(const vector<int>& a,int bit){
    if(bit<0)return 0;
    vector<int> l,r;
    for(int i=0;i<a.size();i++){
        if((a[i]>>bit)&1)l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    if(l.empty())return dfs(r,bit-1);
    if(r.empty())return dfs(l,bit-1);
    return min(dfs(l,bit-1),dfs(r,bit-1))+(1ll<<bit);
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<dfs(a,29)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}