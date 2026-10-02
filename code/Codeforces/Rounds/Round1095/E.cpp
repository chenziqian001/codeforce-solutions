#include<bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree{
    int n;
    vector<int> mn,lz;
    SegTree(int n):n(n),mn(4*(n+1),0),lz(4*(n+1),0){}
    void push(int p){
        if(lz[p]){
            mn[2*p]+=lz[p];lz[2*p]+=lz[p];
            mn[2*p+1]+=lz[p];lz[2*p+1]+=lz[p];
            lz[p]=0;
        }
    }
    // 区间加法
    void add(int p,int l,int r,int ql,int qr,int v){
        if(ql>r||qr<l)return;
        if(ql<=l&&r<=qr){mn[p]+=v;lz[p]+=v;return;}
        push(p);
        int mid=(l+r)/2;
        add(2*p,l,mid,ql,qr,v);
        add(2*p+1,mid+1,r,ql,qr,v);
        mn[p]=min(mn[2*p],mn[2*p+1]);
    }
    // 单点修改
    void upd(int p,int l,int r,int pos,int v){
        if(l==r){mn[p]=v;return;}
        push(p);
        int mid=(l+r)/2;
        if(pos<=mid)upd(2*p,l,mid,pos,v);
        else upd(2*p+1,mid+1,r,pos,v);
        mn[p]=min(mn[2*p],mn[2*p+1]);
    }
    // 区间查询最小值
    int query(int p,int l,int r,int ql,int qr){
        if(ql>r||qr<l)return 1e18;
        if(ql<=l&&r<=qr)return mn[p];
        push(p);
        int mid=(l+r)/2;
        return min(query(2*p,l,mid,ql,qr),query(2*p+1,mid+1,r,ql,qr));
    }
};

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    
    int m=max(n+2,mx+2);
    SegTree st(m);
    vector<int> cnt(m); 
    int mex=0;
    st.upd(1,0,m,0,-1); 
    
    for(int i=0;i<n;i++){
        int x=a[i];
        if(cnt[x]||x>mex){
            st.add(1,0,m,0,(x-1)/2,1); 
        }
        else{
            st.upd(1,0,m,x,1e18); 
            st.add(1,0,m,0,x,1); 
        }
        cnt[x]++; 
        while(1){
            if(st.query(1,0,m,0,mex)<0) break; 
            mex++; 
            st.add(1,0,m,0,mex,-1); 
            if(cnt[mex]){
                st.upd(1,0,m,mex,1e18); 
                st.add(1,0,m,0,(mex-1)/2,-1); 
                st.add(1,0,m,0,mex,1); 
            }
        }
        cout<<mex<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}