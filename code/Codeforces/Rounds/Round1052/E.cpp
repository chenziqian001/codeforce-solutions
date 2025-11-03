#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;

int t[N<<2];int tag[N<<2];
void build(int i,int l,int r){
    tag[i]=0;t[i]=0;
    if(l==r){    
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}
void update(int i,int l,int r,int ql,int qr){
    if(ql>r || qr<l) return;
    if(ql<=l && r<=qr){
        t[i]++;
        tag[i]++;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,ql,qr);
    update(i*2+1,mid+1,r,ql,qr);
    t[i]=max(t[i*2],t[i*2+1])+tag[i];
}

void del(int i,int l,int r,int pos,int val=0){
    if(pos<l || pos>r) return;
    if(l==r){
        t[i]=-val;
        return;
    }
    int mid=(l+r)/2;
    val+=tag[i];
    if(pos<=mid) del(i*2,l,mid,pos,val);
    else del(i*2+1,mid+1,r,pos,val);
    t[i]=max(t[i*2],t[i*2+1])+tag[i];
}


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n);
    for(int i=0;i<n;i++){
        update(1,0,n,0,a[i]);
        del(1,0,n,a[i]);
        cout<<t[1]<<" ";
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}