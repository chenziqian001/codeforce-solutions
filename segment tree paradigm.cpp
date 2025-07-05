#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e5+10;
struct Node{
    int l,r,len;
    int sum1,lmax1,rmax1,tmax1;
    int sum0,lmax0,rmax0,tmax0;
    int lazy;
    Node():l(0),r(0),len(0),sum1(0),lmax1(0),rmax1(0),tmax1(0),sum0(0),lmax0(0),rmax0(0),tmax0(0),lazy(-1){}
} tr[N<<2];

int a[N];
int n,m;

void push_up(Node& u,const Node& l,const Node& r){
    u.len=l.len+r.len;

    u.sum1=l.sum1+r.sum1;
    u.lmax1=(l.len==l.lmax1?l.lmax1+r.lmax1:l.lmax1);
    u.rmax1=(r.len==r.rmax1?r.rmax1+l.rmax1:r.rmax1);
    u.tmax1=max({l.tmax1,r.tmax1,l.rmax1+r.lmax1});

    u.sum0=l.sum0+r.sum0;
    u.lmax0=(l.len==l.lmax0?l.lmax0+r.lmax0:l.lmax0);
    u.rmax0=(r.len==r.rmax0?r.rmax0+l.rmax0:r.rmax0);
    u.tmax0=max({l.tmax0,r.tmax0,l.rmax0+r.lmax0});    
}

void push_up(int u){
    push_up(tr[u],tr[u<<1],tr[u<<1|1]);
}

void apply_tag(int u,int op){
    if(op==0){
        tr[u].sum1=tr[u].lmax1=tr[u].rmax1=tr[u].tmax1=0;
        tr[u].sum0=tr[u].lmax0=tr[u].rmax0=tr[u].tmax0=tr[u].len;
        tr[u].lazy=0;
    }
    else if(op==1){
        tr[u].sum1=tr[u].lmax1=tr[u].rmax1=tr[u].tmax1=tr[u].len;
        tr[u].sum0=tr[u].lmax0=tr[u].rmax0=tr[u].tmax0=0;
        tr[u].lazy=1;
    }
    else if(op==2){
        swap(tr[u].sum1,tr[u].sum0);
        swap(tr[u].lmax1,tr[u].lmax0);
        swap(tr[u].rmax1,tr[u].rmax0);
        swap(tr[u].tmax1,tr[u].tmax0);
        if(tr[u].lazy==0) tr[u].lazy=1;
        else if(tr[u].lazy==1) tr[u].lazy=0;
        else if(tr[u].lazy==2) tr[u].lazy=-1;
        else tr[u].lazy=2;
    }
}   
void push_down(int u){
    if(tr[u].lazy==-1) return;
    apply_tag(u<<1,tr[u].lazy);
    apply_tag(u<<1|1,tr[u].lazy);
    tr[u].lazy=-1;
}
    
void build(int u,int l,int r){
    tr[u].l=l;
    tr[u].r=r;
    tr[u].len=r-l+1;
    tr[u].lazy=-1;
    if(l==r){
        if(a[l]){
            tr[u].sum1=tr[u].lmax1=tr[u].rmax1=tr[u].tmax1=1;
            tr[u].sum0=tr[u].lmax0=tr[u].rmax0=tr[u].tmax0=0;
        }
        else{
            tr[u].sum0=tr[u].lmax0=tr[u].rmax0=tr[u].tmax0=1;
            tr[u].sum1=tr[u].lmax1=tr[u].rmax1=tr[u].tmax1=0;
        }
        return ;
    }
    int mid=(l+r)/2;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    push_up(u);
}

void update(int u,int l,int r,int op){
    if(tr[u].l>r||tr[u].r<l) return;
    if(tr[u].l>=l&&tr[u].r<=r){
        apply_tag(u,op);
        return;
    }
    push_down(u);
    update(u<<1,l,r,op);
    update(u<<1|1,l,r,op);
    push_up(u);
}

Node query(int u,int l,int r){
    if(tr[u].l>r||tr[u].r<l) return Node();
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }
    push_down(u);
    int mid=(tr[u].l+tr[u].r)/2;
    Node left=query(u<<1,l,r);
    Node right=query(u<<1|1,l,r);
    Node res;
    push_up(res,left,right);
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        int op,l,r;
        cin>>op>>l>>r;
        l++,r++;
        if(op<=2){
            update(1,l,r,op);
        }
        else{
            Node res=query(1,l,r);
            if(op==3){
                cout<<res.sum1<<'\n';
            }
            else{
                cout<<res.tmax1<<'\n';
            }
        }
    }
    system("pause");
    return 0;
}

    





