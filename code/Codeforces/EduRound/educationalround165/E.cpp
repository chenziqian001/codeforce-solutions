#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> mn(4*n+5),lz(4*n+5);
    auto apply=[&](int p,int v){
        mn[p]+=v;
        lz[p]+=v;
    };

    auto push=[&](int p){
        if(lz[p]){
            apply(p*2,lz[p]);
            apply(p*2+1,lz[p]);
            lz[p]=0;
        }
    };

    auto update=[&](auto& self,int p,int l,int r,int ql,int qr,int v)->void{
        if(ql>r||qr<l)return;
        if(ql<=l&&r<=qr){
            apply(p,v);
            return;
        }
        push(p);
        int mid=(l+r)/2;
        self(self,p*2,l,mid,ql,qr,v);
        self(self,p*2+1,mid+1,r,ql,qr,v);
        mn[p]=min(mn[p*2],mn[p*2+1]);
    };

    auto query=[&](auto& self,int p,int l,int r,int ql,int qr)->int{
        if(ql>r||qr<l)return 1e9; 
        if(ql<=l&&r<=qr)return mn[p];
        push(p);
        int mid=(l+r)/2;
        return min(self(self,p*2,l,mid,ql,qr),self(self,p*2+1,mid+1,r,ql,qr));
    };

    vector<int> pr(n+1),pr2(n+1);
    int cut=0,res=0;

    for(int i=1;i<=n;i++){
        int x=a[i];
        update(update,1,1,n,pr[x]+1,i,1);
        if(pr[x]>0) update(update,1,1,n,pr2[x]+1,pr[x],-1);
        if(query(query,1,1,n,cut+1,i)==0){
            if(pr[x]>0) update(update,1,1,n,pr2[x]+1,pr[x],1);
            update(update,1,1,n,pr[x]+1,i,-1);
            res++;
            cut=i;
        }
        else{
            pr2[x]=pr[x];
            pr[x]=i;
        }
    }

    cout<<res<<'\n';

    


}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--) solve();
    //system("pause");
    return 0;
}