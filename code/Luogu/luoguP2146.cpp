#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int n;
    vector<int> sum,tag;
    SegTree(int n):n(n),sum(n<<2,0),tag(n<<2,-1){}
    void pushup(int p){sum[p]=sum[p<<1]+sum[p<<1|1];}
    void pushdown(int p,int l,int r){
        if(tag[p]!=-1){
            int mid=(l+r)>>1;
            tag[p<<1]=tag[p];
            sum[p<<1]=tag[p]*(mid-l+1);
            tag[p<<1|1]=tag[p];
            sum[p<<1|1]=tag[p]*(r-mid);
            tag[p]=-1;
        }
    }
    void modify(int p,int l,int r,int ql,int qr,int v){
        if(ql<=l&&r<=qr){
            sum[p]=v*(r-l+1);
            tag[p]=v;
            return;
        }
        pushdown(p,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid)modify(p<<1,l,mid,ql,qr,v);
        if(qr>mid)modify(p<<1|1,mid+1,r,ql,qr,v);
        pushup(p);
    }
};

struct HLD{
    int n,tot;
    vector<vector<int>> g;
    vector<int> sz,fa,son,top,dfn;
    SegTree st;
    HLD(int n):n(n),tot(0),g(n),sz(n),fa(n),son(n,-1),top(n),dfn(n),st(n){}
    void dfs1(int u){
        sz[u]=1;
        for(int v:g[u]){
            dfs1(v);
            sz[u]+=sz[v];
            if(son[u]==-1||sz[v]>sz[son[u]])son[u]=v;
        }
    }
    void dfs2(int u,int t){
        top[u]=t;dfn[u]=++tot;
        if(son[u]!=-1)dfs2(son[u],t);
        for(int v:g[u])if(v!=son[u])dfs2(v,v);
    }
    int install(int u){
        int pre=st.sum[1];
        while(top[u]!=0){
            st.modify(1,1,n,dfn[top[u]],dfn[u],1);
            u=fa[top[u]];
        }
        st.modify(1,1,n,dfn[0],dfn[u],1);
        return st.sum[1]-pre;
    }
    int uninstall(int u){
        int pre=st.sum[1];
        st.modify(1,1,n,dfn[u],dfn[u]+sz[u]-1,0);
        return pre-st.sum[1];
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    HLD hld(n);
    for(int i=1;i<n;i++){
        cin>>hld.fa[i];
        hld.g[hld.fa[i]].push_back(i);
    }
    hld.dfs1(0);
    hld.dfs2(0,0);

    int q;
    cin>>q;
    while(q--){
        string op;int x;
        cin>>op>>x;
        if(op[0]=='i') cout<<hld.install(x)<<'\n';
        else cout<<hld.uninstall(x)<<'\n';
    }
    //system("pause");
}