#include<bits/stdc++.h>
using namespace std;
template<int N>
struct HLD{
    int tot;
    vector<int> g[N];
    int sz[N],fa[N],dep[N],son[N],top[N],dfn[N],rnk[N];
    void add(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs1(int u,int f){
        sz[u]=1;fa[u]=f;dep[u]=dep[f]+1;
        for(int v:g[u]){
            if(v==f)continue;
            dfs1(v,u);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]])son[u]=v;//找重儿子
        }
    }
    void dfs2(int u,int t){
        top[u]=t;dfn[u]=++tot;rnk[tot]=u;//记录链头与dfs序映射
        if(!son[u])return;
        dfs2(son[u],t);//优先走重儿子，保证重链dfs序连续
        for(int v:g[u]){
            if(v!=fa[u]&&v!=son[u])dfs2(v,v);//轻链顶点作为新链头
        }
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            u=fa[top[u]];//向上跳重链
        }
        return dep[u]<dep[v]?u:v;
    }
    //路径操作示例(需配合线段树或树状数组)
    void op_path(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            //操作区间 [dfn[top[u]], dfn[u]]
            u=fa[top[u]];
        }
        if(dep[u]>dep[v])swap(u,v);
        //操作区间 [dfn[u], dfn[v]]
    }
    void op_tree(int u){
        //操作区间 [dfn[u], dfn[u]+sz[u]-1]
    }
};