#include<bits/stdc++.h>
using namespace std;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    int q;
    cin>>q;
    vector<array<int8_t,101>> tag(4*n+1);


    auto build=[&](auto self,int p,int l,int r)->void{
        for(int i=1;i<=100;i++)tag[p][i]=i;
        if(l==r)return;
        int mid=(l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1|1,mid+1,r);
    };

    auto pushdown=[&](int p){
        bool ok=0;
        for(int i=1;i<=100;i++){
            if(tag[p][i]!=i){
                ok=1;
                break;
            }
        }
        if(!ok)return;
        for(int i=1;i<=100;i++){
            tag[p<<1][i]=tag[p][tag[p<<1][i]];
            tag[p<<1|1][i]=tag[p][tag[p<<1|1][i]];
        }
        for(int i=1;i<=100;i++)tag[p][i]=i;
    };


    auto update=[&](auto self,int p,int l,int r,int ql,int qr,int x,int y)->void{
        if(ql<=l&&r<=qr){
            for(int i=1;i<=100;i++){
                if(tag[p][i]==x)tag[p][i]=y;
            }
            return;
        }
        pushdown(p);
        int mid=(l+r)>>1;
        if(ql<=mid)self(self,p<<1,l,mid,ql,qr,x,y);
        if(qr>mid)self(self,p<<1|1,mid+1,r,ql,qr,x,y);
    };

    auto query=[&](auto self,int p,int l,int r)->void{
        if(l==r){
            a[l]=tag[p][a[l]];
            return;
        }
        pushdown(p);
        int mid=(l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1|1,mid+1,r);
    };
    
    build(build,1,1,n);
    while(q--){
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        if(x!=y)update(update,1,1,n,l,r,x,y);
    }
    query(query,1,1,n);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<'\n';
    //system("pause");


}