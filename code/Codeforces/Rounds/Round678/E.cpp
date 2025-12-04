#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t[N<<2];
int last[N];
int a[N];
bool vis[N];

void upd(int i,int l,int r,int pos,int val){
    if(l==r){
        t[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) upd(i*2,l,mid,pos,val);
    else upd(i*2+1,mid+1,r,pos,val);
    t[i]=min(t[i*2],t[i*2+1]);
}

int query(int i,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr){
        return t[i];
    }
    int mid=(l+r)/2;
    if(qr<=mid) return query(i*2,l,mid,ql,qr);
    else if(ql>mid) return query(i*2+1,mid+1,r,ql,qr);
    else return min(query(i*2,l,mid,ql,qr),query(i*2+1,mid+1,r,ql,qr));
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        if(a[i]>1) vis[1]=true;
        if(a[i]>1 && query(1,1,n,1,a[i]-1)>last[a[i]]) vis[a[i]]=true;
        last[a[i]]=i;
        upd(1,1,n,a[i],i); 
    }

    for(int i=2;i<=n+1;i++){
        if(query(1,1,n,1,i-1)>last[i]) vis[i]=1;
    }

    int res=1;
    while(vis[res]){
        res++;
    }
    cout<<res<<'\n';

    //system("pause");
    return 0;
}