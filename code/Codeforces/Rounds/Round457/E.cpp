#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)

struct SegTree{
    vector<int> tr,lz;
    SegTree(int n):tr(n<<2,0),lz(n<<2,0){}
    void up(int p){tr[p]=tr[ls]+tr[rs];}
    void down(int p,int l,int r){
        if(lz[p]){
            int mid=(l+r)>>1;
            tr[ls]+=lz[p]*(mid-l+1);lz[ls]+=lz[p];
            tr[rs]+=lz[p]*(r-mid);lz[rs]+=lz[p];
            lz[p]=0;
        }
    }
    void build(int p,int l,int r,vector<int>&a,vector<int>&rnk){
        if(l==r){tr[p]=a[rnk[l]];return;}
        int mid=(l+r)>>1;
        build(ls,l,mid,a,rnk);
        build(rs,mid+1,r,a,rnk);
        up(p);
    }
    void add(int p,int l,int r,int ql,int qr,int v){
        if(ql>qr)return;
        if(ql<=l&&r<=qr){tr[p]+=v*(r-l+1);lz[p]+=v;return;}
        down(p,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid)add(ls,l,mid,ql,qr,v);
        if(qr>mid)add(rs,mid+1,r,ql,qr,v);
        up(p);
    }
    int ask(int p,int l,int r,int ql,int qr){
        if(ql>qr)return 0;
        if(ql<=l&&r<=qr)return tr[p];
        down(p,l,r);
        int mid=(l+r)>>1,ans=0;
        if(ql<=mid)ans+=ask(ls,l,mid,ql,qr);
        if(qr>mid)ans+=ask(rs,mid+1,r,ql,qr);
        return ans;
    }
};

struct HLD{
    int n,R,tot;
    vector<vector<int>> g;
    vector<int> a,sz,fa,dep,son,top,dfn,rnk;
    SegTree seg;
    HLD(int n_):n(n_),R(1),tot(0),g(n_+1),a(n_+1,0),sz(n_+1,0),fa(n_+1,0),
                dep(n_+1,0),son(n_+1,0),top(n_+1,0),dfn(n_+1,0),rnk(n_+1,0),seg(n_){}
    void dfs1(int u,int f){
        fa[u]=f;dep[u]=dep[f]+1;sz[u]=1;
        for(int v:g[u]){
            if(v==f)continue;
            dfs1(v,u);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]])son[u]=v;
        }
    }
    void dfs2(int u,int t){
        top[u]=t;dfn[u]=++tot;rnk[tot]=u;
        if(son[u])dfs2(son[u],t);
        for(int v:g[u]){
            if(v!=fa[u]&&v!=son[u])dfs2(v,v);
        }
    }
    void init(){
        dfs1(1,0);
        dfs2(1,1);
        seg.build(1,1,n,a,rnk);
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            u=fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int get_w(int u,int v){
        int x1=lca(u,v),x2=lca(u,R),x3=lca(v,R),res=x1;
        if(dep[x2]>dep[res])res=x2;
        if(dep[x3]>dep[res])res=x3;
        return res;
    }
    int get_z(int w,int r){
        while(top[r]!=top[w]){
            if(fa[top[r]]==w)return top[r];
            r=fa[top[r]];
        }
        return son[w];
    }
    void update(int u,int v,int x){
        int w=get_w(u,v);
        if(w==R){
            seg.add(1,1,n,1,n,x);
        }else if(lca(w,R)!=w){
            seg.add(1,1,n,dfn[w],dfn[w]+sz[w]-1,x);
        }else{
            int z=get_z(w,R);
            seg.add(1,1,n,1,n,x);
            seg.add(1,1,n,dfn[z],dfn[z]+sz[z]-1,-x);
        }
    }
    int query(int w){
        if(w==R){
            return seg.ask(1,1,n,1,n);
        }else if(lca(w,R)!=w){
            return seg.ask(1,1,n,dfn[w],dfn[w]+sz[w]-1);
        }else{
            int z=get_z(w,R);
            return seg.ask(1,1,n,1,n)-seg.ask(1,1,n,dfn[z],dfn[z]+sz[z]-1);
        }
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    if(!(cin>>n>>q))return 0;
    HLD hld(n);
    for(int i=1;i<=n;i++)cin>>hld.a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        hld.g[u].push_back(v);
        hld.g[v].push_back(u);
    }
    hld.init();
    for(int i=0;i<q;i++){
        int op;cin>>op;
        if(op==1){
            int v;cin>>v;
            hld.R=v;
        }else if(op==2){
            int u,v,x;cin>>u>>v>>x;
            hld.update(u,v,x);
        }else{
            int v;cin>>v;
            cout<<hld.query(v)<<"\n";
        }
    }
    //system("pause");
    return 0;
}