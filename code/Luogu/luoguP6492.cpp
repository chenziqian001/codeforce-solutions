#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q;
const int N=2e5+10;
int a[N];
struct Node{
    int u,l,r;
    int len;
    int lm,rm,tm;
}tr[N<<2];

void push_up(int u){
    int l=tr[u].l,r=tr[u].r;
    int mid=(l+r)/2;
    int lr=a[mid];
    int rl=a[mid+1];
    
    Node& left=tr[u<<1];
    Node& right=tr[u<<1|1];
    tr[u].len=left.len+right.len;

    if(lr==rl){
        tr[u].tm=max(left.tm,right.tm);
        tr[u].lm=left.lm;
        tr[u].rm=right.rm;
    }
    else{
        tr[u].tm=max({left.tm,right.tm,left.rm+right.lm});
        tr[u].lm=(left.tm==left.len?left.tm+right.lm:left.lm);
        tr[u].rm=(right.tm==right.len?right.tm+left.rm:right.rm);
    }
    return;
}


void build(int u,int l,int r){
    tr[u].l=l;
    tr[u].r=r;
    tr[u].len=r-l+1;
    if(l==r){
        tr[u].lm=tr[u].rm=tr[u].tm=1;
        return;
    }
    int mid=(l+r)/2;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    push_up(u);
}

void update(int u,int l,int r,int n){
    if(n>r) return;
    if(n<l) return;
    if(l==r){
        a[l]=1-a[l];
        tr[u].lm=tr[u].rm=tr[u].tm=1;
        return;
    }
    int mid=(l+r)/2;
    update(u<<1,l,mid,n);
    update(u<<1|1,mid+1,r,n);
    push_up(u);
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        update(1,1,n,t);
        cout<<tr[1].tm<<'\n';
    }
    return;
}

int main(){
    solve();
    system("pause");
    return 0;
}