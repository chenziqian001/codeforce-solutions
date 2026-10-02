#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n+1),p(n+1);
    int mn=1e9,cu=0,cv=0;
    function<void(int,int,int)> dfs=[&](int node,int fa,int dep){
        d[node]=dep;
        p[node]=fa;
        for(int next:g[node]){
            if(next==fa) continue;
            if(d[next]){
                if(d[node]>d[next] && d[node]-d[next]+1<mn){
                    mn=d[node]-d[next]+1;
                    cu=node;
                    cv=next;
                }
            }
            else dfs(next,node,dep+1);
        }
    };
    dfs(1,0,1);
    int need=(k+1)/2;
    if(mn<=k){
        cout<<2<<'\n';
        cout<<mn<<'\n';
        int cur=cu;
        while(cur!=cv){
            cout<<cur<<" ";
            cur=p[cur];
        }
        cout<<cv<<'\n';
    }
    else{
        cout<<1<<'\n';
        if(mn!=1e9){
            int cur=cu;
            for(int i=0;i<need;i++){
                cout<<cur<<" ";
                cur=p[p[cur]];
            }
            cout<<'\n';
        }
        else{
            vector<vector<int>> tp(2);
            for(int i=1;i<=n;i++){
                tp[d[i]%2].push_back(i);
            }
            int gp=(tp[0].size()>tp[1].size()?0:1);
            for(int i=0;i<need;i++){
                cout<<tp[gp][i]<<" ";
            }
            cout<<'\n';
        }
    }
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