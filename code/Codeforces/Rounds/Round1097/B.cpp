#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    map<int,int> c;
    int mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[x]++;
        mx=max(mx,x);
    }
    vector<int> b;
    b.push_back(mx);
    c[mx]--;
    int cur=0;
    for(int i=1;i<n;i++){
        if(cur==mx) cur++;
        if(c[cur]>0){
            b.push_back(cur);
            c[cur]--;
            cur++;
        }
        else break;
    }
    for(auto p:c){
        while(p.second>0){
            b.push_back(p.first);
            p.second--;
        }
    }
    int res=0;
    int mex=0;
    map<int,int> vis;
    for(int i=0;i<n;i++){
        vis[b[i]]=1;
        while(vis[mex]) mex++;
        res+=mx+mex;
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