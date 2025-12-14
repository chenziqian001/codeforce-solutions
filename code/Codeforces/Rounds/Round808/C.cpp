#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int vis[N];
int fa[N][20],dis[N];
int sum[N];
vector<pair<int,int>> g;
vector<int> t[N];


struct DSU{
    int fa[N];
    void init(int n){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        if(x!=fa[x]){
            fa[x]=find(fa[x]);
        }
        return fa[x];
    }

    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
        fa[x]=y;
        return true;
    }
} dsu;


void kruskal(){
    dsu.init(n);
    for(int i=0;i<m;i++){
        int u=g[i].first;
        int v=g[i].second;
        if(dsu.merge(u,v)){
            vis[i]=1;
            t[u].push_back(v);
            t[v].push_back(u);
        }
    }
}

void dfs1(int node,int f){
    fa[node][0]=f;
    dis[node]=dis[f]+1;
    for(int i=1;i<20;i++){
        fa[node][i]=fa[fa[node][i-1]][i-1];
    }

    for(int next:t[node]){
        if(next!=f){
            dfs1(next,node);
        }
    }
}

void dfs2(int node,int f){
    sum[node]+=sum[f];
    for(int next:t[node]){
        if(next!=f){
            dfs2(next,node);
        }
    }
}


int lca(int u,int v){
    if(dis[u]<dis[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(dis[fa[u][i]]>=dis[v]){
            u=fa[u][i];
        }
    }
    if(u==v) return u;

    for(int i=19;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.emplace_back(u,v);
    }

    kruskal();
    dfs1(1,0);

    for(int i=0;i<m;i++){
        if(!vis[i]){
            int u=g[i].first;
            int v=g[i].second;
            int l=lca(u,v);


            if(dis[u]>dis[v]) swap(u,v);
            if(l==u){
                sum[1]++;
                sum[v]++;
                int p=v;
                for(int i=19;i>=0;i--){
                    if(dis[fa[p][i]]>dis[u]){
                        p=fa[p][i];
                    }
                }
                sum[p]--;
            }
            else{
                sum[u]++;
                sum[v]++;
            }
        }
    }

    dfs2(1,0);
    string res;
    for(int i=1;i<=n;i++){
        if(sum[i]==m-n+1){
            res+='1';
        }
        else{
            res+='0';
        }
    }

    cout<<res<<'\n';
    //system("pause");
}