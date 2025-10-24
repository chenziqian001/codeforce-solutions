#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;

struct Data{
    int cnt;
    int sumk;
    int sumkk;
    Data(int c=0,int s1=0,int s2=0):cnt(c),sumk(s1),sumkk(s2) {}
};

struct segt{
    struct node{
        int l,r;
        Data data;
        int laze;
    };
    vector<node> t;
    int n;
    segt(int n):n(n){
        t.resize(n*4+10);
        build(1,1,n);
    }
    void build(int i,int l,int r){
        t[i].l=l;
        t[i].r=r;
        if(l==r) return;
        int m=(l+r)/2;
        build(i<<1,l,m);
        build(i<<1|1,m+1,r);
    }
    static Data merge(const Data& a,const Data& b){
        return Data(a.cnt+b.cnt,a.sumk+b.sumk,a.sumkk+b.sumkk);
    }
    void push_up(int i){
        t[i].data=merge(t[i<<1].data,t[i<<1|1].data);
    }
    void setpoint(int i,int pos,int cnt){
        if(t[i].l==t[i].r){
            if(cnt<0) t[i].data=Data();
            else t[i].data=Data(1,cnt,1LL*cnt*cnt);
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(pos<=mid) setpoint(i<<1,pos,cnt);
        else setpoint(i<<1|1,pos,cnt);
        push_up(i); 
    }
    void apply(int i,int f){
        auto &cur=t[i].data;
        cur.sumkk+=cur.sumk*f*2+f*f*cur.cnt;
        cur.sumk+=cur.cnt*f;
        t[i].laze+=f;
    }
    void push_down(int i){
        int f=t[i].laze;
        if(!f) return;
        apply(i<<1,f);
        apply(i<<1|1,f);
        t[i].laze=0;
    }
    void update(int o, int l, int r, int f) {
        if (l <= t[o].l && t[o].r <= r) {
            apply(o, f);
            return;
        }
        push_down(o);
        int m = (t[o].l + t[o].r) >> 1;
        if (l <= m) update(o << 1, l, r, f);
        if (r > m) update(o << 1 | 1, l, r, f);
        push_up(o);
    }

    Data query(int i,int l,int r){
        if (l <= t[i].l && t[i].r <= r) {
            return t[i].data;
        }
        push_down(i);
        int m=(t[i].l+t[i].r)/2;
        if(r<=m){
            return query(i<<1,l,r);
        }
        if(l>m){
            return query(i<<1|1,l,r);
        }
        return merge(query(i<<1,l,r),query(i<<1|1,l,r));
    }
    
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,d;
    cin>>q>>d;
    const int mx=2e5;
    segt seg(mx);
    vector<bool> vis(mx+1,false);
    while(q--){
        int x;
        cin>>x;
        if(vis[x]){
            vis[x]=false;
            seg.setpoint(1,x,-1);
            if(x>1) seg.update(1,max(1LL,x-d),x-1,-1);
        }
        else{
            vis[x]=true;
            int cnt=seg.query(1,x,min(x+d,mx)).cnt;
            seg.setpoint(1,x,cnt);
            if(x>1) seg.update(1,max(1LL,x-d),x-1,1);
        }

        cout<<(seg.t[1].data.sumkk-seg.t[1].data.sumk)/2<<'\n';
    }
    return 0;
}

