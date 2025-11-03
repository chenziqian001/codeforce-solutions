#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> path;
    vector<int> p(n);
    int mxdis=0;
    int far=-1;
    function<void(int,int,int)> dfs=[&](int node,int fa,int dis){
        if(dis>mxdis){
            far=node;
            mxdis=dis;
        }
        else if(dis==mxdis && node>far){
            far=node;
        }
        for(int next:t[node]){
            if(next==fa) continue;
            p[next]=node;
            dfs(next,node,dis+1);
        }
    };
    dfs(0,-1,0);
    int u=far;
    far=-1;
    mxdis=0;
    dfs(u,-1,0);
    int v=far;
    while(v!=u){
        path.push_back(v);
        v=p[v];
    }
    path.push_back(u);
    vector<int> res(n);
    vector<int> g(n,-1);
    int m=path.size();
    function<void(int,int)> dfs1=[&](int node,int fa){
        for(int next:t[node]){
            if(next==fa || g[next]!=-1) continue;
            g[next]=g[node];
            dfs1(next,node);
        }
    };

    for(int i=0;i<m;i++){
        g[path[i]]=i;
    }
    for(int i=0;i<m;i++){
        dfs1(path[i],-1);
    }
    for(int i=0;i<n;i++){
        if(m%2==1 && g[i]==m/2){
            res[i]=max(path[0],path[m-1]);
            continue;
        }
        if(g[i]<m/2) res[i]=path[m-1];
        else res[i]=path[0];

    }
    for(int i=0;i<n;i++){
        cout<<res[i]+1<<'\n';
    }

}

