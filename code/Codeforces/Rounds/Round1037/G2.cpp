#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
class segt{
public:
    int n;
    int premax[N*4],sufmax[N*4],t[N*4];
    void push_up(int id){
        premax[id]=max(premax[id*2],premax[id*2+1]+t[id*2]);
        sufmax[id]=max(sufmax[id*2]+t[id*2+1],sufmax[id*2+1]);
        t[id]=t[id*2]+t[id*2+1];
    }
    void init(int id,int l,int r){
        if(l==r){
            premax[id]=sufmax[id]=t[id]=1;
            return;
        }
        int mid=(l+r)/2;
        init(id*2,l,mid);
        init(id*2+1,mid+1,r);
        push_up(id);
    }
    void modify(int id,int l,int r,int pos,int val){
        if(l==r){
            premax[id]=sufmax[id]=t[id]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) modify(id*2,l,mid,pos,val);
        else modify(id*2+1,mid+1,r,pos,val);
        push_up(id);
    }
    pair<int,int> gpm(int id,int l,int r,int ql,int qr){
        if(l==ql && r==qr) return {premax[id],t[id]};
        int mid=(l+r)/2;
        if(mid>=qr) return gpm(id*2,l,mid,ql,qr);
        else if(mid<ql) return gpm(id*2+1,mid+1,r,ql,qr);
        else{
            pair<int,int> pl=gpm(id*2,l,mid,ql,mid);
            pair<int,int> pr=gpm(id*2+1,mid+1,r,mid+1,qr);
            return {max(pl.first,pl.second+pr.first),pl.second+pr.second};
        }
    }
    pair<int,int> gsm(int id,int l,int r,int ql,int qr){
        if(l==ql && r==qr) return {sufmax[id],t[id]};
        int mid=(l+r)/2;
        if(mid>=qr) return gsm(id*2,l,mid,ql,qr);
        else if(mid<ql) return gsm(id*2+1,mid+1,r,ql,qr);
        else{
            pair<int,int> pl=gsm(id*2,l,mid,ql,mid);
            pair<int,int> pr=gsm(id*2+1,mid+1,r,mid+1,qr);
            return {max(pl.first+pr.second,pr.first),pl.second+pr.second};
        }
    }
    segt() {}
    void init(int n){
        this->n=n;
        init(1,0,n-1);
    }
};
segt st;
void solve(){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> id(n);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    st.init(n);
    int res=0;
    int pos=0;
    for(int i=0;i<n;i++){
        int j=id[i];
        while(max(st.gsm(1,0,n-1,0,j).first,st.gpm(1,0,n-1,j,n-1).first)>=0){
            st.modify(1,0,n-1,id[pos++],-1);
        }
        if(pos) res=max(a[id[pos-1]]-a[j],res);
    }
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}