#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N];int dep[N];vector<int> g[N];

int root[N];
int ls[N*80],rs[N*80];
int mini[N*80];

int cnt=0;



int insert(int pos,int val,int l,int r){
    int i=++cnt;
    mini[i]=val;
    if(l==r){
        return i; 
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        ls[i]=insert(pos,val,l,mid);
    }
    else rs[i]=insert(pos,val,mid+1,r);
    return i;
}

int merge(int l,int r,int i,int j){
    int node=++cnt;
    if(i==0 || j==0){
        int k=i+j;
        mini[node]=mini[k];
        ls[node]=ls[k];
        rs[node]=rs[k];
        return node;
    }
    mini[node]=min(mini[i],mini[j]);
    int mid=(l+r)/2;
    if(l!=r){
        
        ls[node]=merge(l,mid,ls[i],ls[j]);
        rs[node]=merge(mid+1,r,rs[i],rs[j]);
    }
    
    return node;
}


int query(int ql,int qr,int l,int r,int i){
    if(ql<=l && r<=qr){
        return mini[i];
    }

    int mid=(l+r)/2;
    int res=INT_MAX;
    if(ql<=mid) res=min(res,query(ql,qr,l,mid,ls[i]));
    if(qr>mid) res=min(res,query(ql,qr,mid+1,r,rs[i]));
    return res;
}


void dfs(int node,int fa){
    dep[node]=dep[fa]+1;
    root[node]=insert(dep[node],a[node],1,n);
    for(int next:g[node]){
        if(next==fa) continue;
        dfs(next,node);
        root[node]=merge(1,n,root[node],root[next]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int rt;
    mini[0]=INT_MAX;
    cin>>n>>rt;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(rt,0);
    cin>>m;
    int last=0;
    while(m--){
        int x,k;
        cin>>x>>k;
        x=(x+last)%n+1;
        k=(k+last)%n;
        int ql=dep[x];
        int qr=min(n,dep[x]+k);
        int res=query(ql,qr,1,n,root[x]);
        last=res;
        cout<<res<<'\n';

    }
    //system("pause");
    return 0;
}