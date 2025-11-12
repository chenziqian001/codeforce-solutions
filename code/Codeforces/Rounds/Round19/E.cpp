#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,id;
};

vector<vector<edge>> g;
vector<int> dep;
vector<int> dfn;
vector<array<int,2>> diff;
vector<array<int,2>> diffsum;
int bad=0;
int p=0;

void dfs(int node,int fa,int fid){
    dfn[node]=++p;
    for(auto [next,id]:g[node]){
        if(!dfn[next]){
            dep[next]=dep[node]^1;
            dfs(next,node,id);
        }
        else if(next!=fa && dfn[next]<dfn[node]){
            int t=dep[node]^dep[next];
            if(!t) bad++;
            diff[node][t]++;
            diff[next][t]--;
            diffsum[id][t]++;
        }

    }
    diffsum[fid]=diff[node];
    diff[fa][0]+=diff[node][0];
    diff[fa][1]+=diff[node][1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;

    g.resize(n);
    dep.resize(n);
    dfn.resize(n);
    diff.resize(n+1,{0,0});
    diffsum.resize(m+1,{0,0});
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for(int i=0;i<n;i++){
        if(!dfn[i]) dfs(i,n,m);
    }
    vector<int> res;
    for(int i=0;i<m;i++){
        auto [odd,even]=diffsum[i];
        if(bad==0 || (odd==bad && even==0)) res.push_back(i);
    }

    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x+1<<" ";
    }
    cout<<'\n';
    //system("pause");
}