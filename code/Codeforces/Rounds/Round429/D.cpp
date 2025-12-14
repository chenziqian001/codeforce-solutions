#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int M=N*50;
 
int root[N];
int ls[M],rs[M],sum[M];
 
int cnt=0;
void insert(int &node,int l,int r,int pos){
    if(!node) node=++cnt;
    sum[node]++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(pos<=mid) insert(ls[node],l,mid,pos);
    else insert(rs[node],mid+1,r,pos);
}
 
int merge(int u,int v){
    if(!u || !v) return u|v;
    int x=++cnt;
    sum[x]=sum[u]+sum[v];
    ls[x]=merge(ls[u],ls[v]);
    rs[x]=merge(rs[u],rs[v]);
    return x;
}
 
 
int query(int u,int v,int l,int r,int k){
    if(l==r) return l;
    int s=sum[ls[v]]-sum[ls[u]];
    int mid=(l+r)/2;
    if(k<=s) return query(ls[u],ls[v],l,mid,k);
    else return query(rs[u],rs[v],mid+1,r,k-s);
}
 
 
int counter(int u,int v,int l,int r,int pos){
    if(l==r) return sum[v]-sum[u];
    int mid=(l+r)/2;
    if(pos<=mid) return counter(ls[u],ls[v],l,mid,pos);
    else return counter(rs[u],rs[v],mid+1,r,pos);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cnt=0;
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
 
    sort(b.begin()+1,b.begin()+1+n);
    int nn = unique(b.begin() + 1, b.begin() + n + 1)-b.begin()-1;
 
    for(int i=1;i<=n;i++){
        insert(root[i],1,nn,lower_bound(b.begin()+1,b.begin()+1+nn,a[i])-b.begin());
    }
    for(int i=2;i<=n;i++){
        root[i]=merge(root[i],root[i-1]);
    }
 
 
    while(m--){
        int ql, qr, k;
        cin>>ql>>qr>>k;
        int d=(qr-ql+1)/k+1;
        int num=-1;
        for(int i=1;i*d<=(qr-ql+1);i++){
            int tmp=query(root[ql-1],root[qr],1,nn,i*d);
 
            int cnt=counter(root[ql-1],root[qr],1,nn,tmp);
            if(cnt>=d){
                num=tmp;
                break;
            } 
        }
        if(num==-1) cout<<num<<'\n'; 
        else cout<<b[num]<<'\n';
    }
    //system("pause");
    return 0;
 
}