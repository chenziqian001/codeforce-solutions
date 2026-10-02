#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=100005;
vector<int> t[N<<2];
int a[N];

vector<int> merge(const vector<int>& x,const vector<int>& y){
    vector<int> res;
    int i=0,j=0;
    while(i<x.size() && j<y.size() && res.size()<31){
        if(x[i]<y[j]) res.push_back(x[i++]);
        else res.push_back(y[j++]);
    }
    while(i<x.size()&&res.size()<31) res.push_back(x[i++]);
    while(j<y.size()&&res.size()<31) res.push_back(y[j++]);
    return res;
}

void build(int p,int l,int r){
    if(l==r){
        t[p]={a[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p]=merge(t[p<<1],t[p<<1|1]);
}

vector<int> query(int p,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr) return t[p];
    int mid=(l+r)>>1;
    if(qr<=mid) return query(p<<1,l,mid,ql,qr);
    if(ql>mid) return query(p<<1|1,mid+1,r,ql,qr);
    return merge(query(p<<1,l,mid,ql,qr),query(p<<1|1,mid+1,r,ql,qr));
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        vector<int> v=query(1,1,n,l,r);
        int ans=1ll<<60;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                ans=min(ans,v[i]|v[j]);
            }
        }
        cout<<ans<<"\n";
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