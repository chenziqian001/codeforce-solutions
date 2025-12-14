#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int root[N],a[N],b[N];
int ls[N*40],rs[N*40],sum[N*40];
int idx=0;
void insert(int &node,int l,int r,int pos){
    if(!node) node=++idx;
    sum[node]++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(pos<=mid) insert(ls[node],l,mid,pos);
    else insert(rs[node],mid+1,r,pos);
}

int merge(int i,int j){
    if(!i || !j) return i|j;
    int k=++idx;
    sum[k]=sum[i]+sum[j];
    ls[k]=merge(ls[i],ls[j]);
    rs[k]=merge(rs[i],rs[j]);
    return k;
}

int query(int i,int j,int l,int r,int k){
    if(l==r) return l;
    int s=sum[ls[i]]-sum[ls[j]];
    int mid=(l+r)/2;
    if(k<=s) return query(ls[i],ls[j],l,mid,k);
    else return query(rs[i],rs[j],mid+1,r,k-s);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        insert(root[i],1,m,lower_bound(b+1,b+1+m,a[i])-b);
    }
    for(int i=2;i<=n;i++){
        root[i]=merge(root[i],root[i-1]);
    }

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int res=query(root[r],root[l-1],1,m,k);
        cout<<b[res]<<'\n';
    }
    cout<<'\n';
    //system("pause");
    return 0;
}