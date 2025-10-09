#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,q;
int a[N],mxl[N<<2],mxr[N<<2],mnl[N<<2],mnr[N<<2],ans[N<<2];

inline void push_up(int now){
    mxl[now]=max(mxl[now*2],mxl[now*2+1]);
    mxr[now]=max(mxr[now*2],mxr[now*2+1]);
    mnl[now]=max(mnl[now*2],mnl[now*2+1]);
    mnr[now]=max(mnr[now*2],mnr[now*2+1]);
    ans[now]=max({ans[now*2],ans[now*2+1],max(mxr[now*2+1]+mnl[now*2],mxl[now*2]+mnr[now*2+1])});
}
void init(int now,int v){
    mxr[now]=a[v]-v;
    mxl[now]=a[v]+v;
    mnr[now]=-a[v]-v;
    mnl[now]=-a[v]+v;
    ans[now]=0;
}

void build(int l,int r,int now){
    if(l==r){
        init(now,l);
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    push_up(now);
}

void modify(int l,int r,int now,int p){
    if(l==r){
        init(now,p);
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid) modify(l,mid,now*2,p);
    else modify(mid+1,r,now*2+1,p);
    push_up(now);
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    cout<<ans[1]<<'\n';
    while(q--){
        int p,x;
        cin>>p>>x;
        a[p]=x,modify(1,n,1,p);
        cout<<ans[1]<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}