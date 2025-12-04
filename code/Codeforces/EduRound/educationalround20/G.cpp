#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int M=20;
const int inf=2e9;

int n,k,q;
vector<int> b;
const int mx=6e6+5;
int st[N*2][M];

struct node{
    int ls,rs;
    int mini;
    int lazy;
}t[mx];

int root=0;
int cnt=0;

void build_st(){
    int m=2*n;

    for(int i=0;i<m;i++){
        st[i][0]=(i<n?b[i]:b[i-n]);
    }
    for(int j=1;j<20;j++){
        for(int i=0;i+(1<<j)<=m;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int st_q(int L,int R){
    int len=R-L+1;
    int k=log2(len);
    return min(st[L][k],st[R-(1<<k)+1][k]);
}
int get_initial(int L,int R){
    int len=R-L+1;
    if(len>=n) return st_q(0,n-1);

    int l=(L-1)%n;
    int r=(R-1)%n;
    if(l<=r) return st_q(l,r);
    else return st_q(l,r+n);
}

int new_node(int l,int r){
    cnt++;
    t[cnt].ls=t[cnt].rs=0;
    t[cnt].lazy=0;
    t[cnt].mini=get_initial(l,r);
    return cnt;
}

void push_down(int i,int l,int r){
    if(!t[i].lazy) return;
    int mid=(l+r)>>1;

    if(!t[i].ls) t[i].ls=new_node(l,mid);
    if(!t[i].rs) t[i].rs=new_node(mid+1,r);

    t[t[i].ls].mini=t[i].lazy;
    t[t[i].ls].lazy=t[i].lazy;

    t[t[i].rs].mini=t[i].lazy;
    t[t[i].rs].lazy=t[i].lazy;
    t[i].lazy=0;
}
void push_up(int i,int l,int r){
    int mid=(l+r)>>1;
    int vl=t[i].ls?t[t[i].ls].mini:get_initial(l,mid);
    int vr=t[i].rs?t[t[i].rs].mini:get_initial(mid+1,r);
    t[i].mini=min(vl,vr);
}

void upd(auto &p,int l,int r,int ql,int qr,int val){
    if(!p) p=new_node(l,r);
    if(ql<=l && r<=qr){
        t[p].mini=val;
        t[p].lazy=val;
        return;
    }
    push_down(p,l,r);
    int mid=(l+r)/2;
    if(ql<=mid) upd(t[p].ls,l,mid,ql,qr,val);
    if(qr>mid) upd(t[p].rs,mid+1,r,ql,qr,val);
    push_up(p,l,r); 
}

int query(int i,int l,int r,int ql,int qr){
    if(!i) return get_initial(max(l,ql),min(r,qr));

    if(ql<=l && r<=qr) return t[i].mini;
    push_down(i,l,r);
    int mid=(l+r)/2;
    int res=inf;

    if(ql<=mid) res=min(res,query(t[i].ls,l,mid,ql,qr));
    if(qr>mid) res=min(res,query(t[i].rs,mid+1,r,ql,qr));
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    b.resize(n);
    for(int i=0;i<n;i++) cin>>b[i];

    build_st();
    int ttl=n*k;

    
    cin>>q;
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;


        if(op==1){
            int val;
            cin>>val;
            upd(root,1,ttl,l,r,val);
        }
        else cout<<query(root,1,ttl,l,r)<<'\n';
    }
    //system("pause");
    return 0;
}


