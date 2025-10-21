#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> s(n),d(n),ds(n),dss;
    auto dfs1=[&](auto &&self,int node,int fa)->void{
        ds[d[node]]++;
        int sz=1;
        for(int next:t[node]){
            if(next==fa) continue;
            d[next]=d[node]+1;
            self(self,next,node);
            sz+=s[next];
        }
        s[node]=sz;
    };
    dfs1(dfs1,0,-1);
    dss=ds;
    for(int i=n-2;i>=0;i--){
        dss[i]+=dss[i+1];
    }
    int res1=0;
    int res2=0;
    auto dfs2=[&](auto &&self,int node,int fa)->void{
        res1+=2*d[node]*(dss[d[node]]-s[node]);
        int subt=s[node]-1;
        int sum=0;
        for(int next:t[node]){
            if(next==fa) continue;
            sum+=(subt-s[next])*s[next];
            self(self,next,node);
        }
        res2+=(2*d[node]+1)*(sum/2);
    };
    dfs2(dfs2,0,-1);
    for(int i=0;i<n;i++){
        res2+=i*ds[i]*(ds[i]-1);
    }
    cout<<res1-res2<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}