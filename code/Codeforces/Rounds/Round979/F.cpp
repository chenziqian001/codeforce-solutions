#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    
    vector<int>pos(n+1,1e9);
    vector<int>nxt(n+1,1e9);


    for(int i=n;i>=1;i--){
        nxt[i]=pos[a[i]];
        pos[a[i]]=i;
    }


    vector<int>tr(4*n+4,1e9);
    auto update=[&](auto& self,int p,int l,int r,int x,int v)->void{
        tr[p]=min(tr[p],v);
        if(l==r)return;
        int mid=(l+r)/2;
        if(x<=mid)self(self,p*2,l,mid,x,v);
        else self(self,p*2+1,mid+1,r,x,v);
    };



    auto query=[&](auto& self,int p,int l,int r,int ql,int qr,int limit)->int{
        if(l>qr||r<ql||tr[p]>=limit)return 1e9;
        if(l==r)return l; 
        int mid=(l+r)/2;
        int res=self(self,p*2,l,mid,ql,qr,limit);
        if(res!=1e9)return res;
        return self(self,p*2+1,mid+1,r,ql,qr,limit);
    };

    vector<int> bad(n+2,1e9);
    for(int i=n;i>=1;i--){
        if(nxt[i]<=n){
            bad[i]=query(query,1,1,n,nxt[i]+1,n,nxt[i]);
            update(update,1,1,n,nxt[i],i);
        }
    }

    vector<int> bd(n+2,1e9);
    for(int i=n;i>=1;i--){
        bd[i]=min(bad[i],bd[i+1]);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(bd[l]<=r){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
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
