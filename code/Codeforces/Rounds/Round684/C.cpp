#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long

struct Node{
    int sum,mx,mn,lz;
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<Node> tr(n*4+1);
    
    auto pushup=[&](int u){
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
        tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
        tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
    };
    
    auto assign=[&](int u,int l,int r,int v){
        tr[u].mx=tr[u].mn=tr[u].lz=v;
        tr[u].sum=(r-l+1)*v;
    };
    
    auto pushdown=[&](int u,int l,int r){
        if(tr[u].lz){
            int mid=l+r>>1;
            assign(u<<1,l,mid,tr[u].lz);
            assign(u<<1|1,mid+1,r,tr[u].lz);
            tr[u].lz=0;
        }
    };
    
    auto build=[&](auto& self,int u,int l,int r)->void{
        if(l==r){
            tr[u].sum=tr[u].mx=tr[u].mn=a[l];
            tr[u].lz=0;
            return;
        }
        int mid=l+r>>1;
        self(self,u<<1,l,mid);
        self(self,u<<1|1,mid+1,r);
        pushup(u);
    };
    
    auto update=[&](auto& self,int u,int l,int r,int L,int R,int v)->void{
        if(tr[u].mn>=v) return;
        if(L<=l&&r<=R&&tr[u].mx<=v){
            assign(u,l,r,v);
            return;
        }
        pushdown(u,l,r);
        int mid=l+r>>1;
        if(L<=mid) self(self,u<<1,l,mid,L,R,v);
        if(R>mid) self(self,u<<1|1,mid+1,r,L,R,v);
        pushup(u);
    };
    
    auto query=[&](auto& self,int u,int l,int r,int L,int R,int& y)->int{
        if(tr[u].mn>y) return 0;
        if(L<=l&&r<=R&&tr[u].sum<=y){
            y-=tr[u].sum;
            return r-l+1;
        }
        pushdown(u,l,r);
        int mid=l+r>>1;
        int res=0;
        if(L<=mid) res+=self(self,u<<1,l,mid,L,R,y);
        if(R>mid) res+=self(self,u<<1|1,mid+1,r,L,R,y);
        return res;
    };
    
    build(build,1,1,n);

    while(q--){
        int tp,x,y;
        cin>>tp>>x>>y;
        if(tp==1){
            update(update,1,1,n,1,x,y);
        }
        else{
            cout<<query(query,1,1,n,x,n,y)<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}