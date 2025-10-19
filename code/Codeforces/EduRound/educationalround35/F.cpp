#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
vector<int> g[N];
int p[N];
set<int> s;
vector<array<int,3>> ans;
pair<int,int> dfs1(int node,int fa,int dis){
    p[node]=fa;
    int pos=node;
    int mxd=dis;
    for(int next:g[node]){
        if(next==fa) continue;
        auto [np,nd]=dfs1(next,node,dis+1);
        if(nd>mxd){
            pos=np;
            mxd=nd;            
        }
    }
    return {pos,mxd};
}
int dfs2(int node,int fa,int mxlen,int rt,int dep){
    int res=dep+mxlen-1;
    for(int next:g[node]){
        if(next==fa) continue;
        res+=dfs2(next,node,mxlen,rt,dep+1);
    }
    ans.push_back({rt,node,node});
    return res;
}
vector<int> get(){
    int u=dfs1(0,-1,0).first;
    int v=dfs1(u,-1,0).first;
    vector<int> res;
    while(p[v]!=-1){
        res.push_back(v);
        v=p[v];
    }
    res.push_back(u);
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n,0);
    vector<int> path=get();
    for(int x:path){
        s.insert(x);
    }
    int m=path.size();
    int res=(m-1)*m/2;
    for(int i=0;i<m;i++){
        int x=path[i];
        int rt;
        int mxlen;
        if(g[x].size()<=2) continue;
        if(i+1<m-i){
            rt=path[m-1];
            mxlen=m-i;
        }
        else{
            rt=path[0];
            mxlen=i+1;
        }
        for(int son:g[x]){
            if(s.count(son)) continue;
            res+=dfs2(son,x,mxlen,rt,1);
        }       
    } 
    cout<<res<<'\n';
    for(int i=m-1;i>=1;i--){
        ans.push_back({path[0],path[i],path[i]});
    }

    for(auto [x,y,z]:ans){
        cout<<x+1<<" "<<y+1<<" "<<z+1<<'\n';
    }
    
    return 0;
}