#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point{
    int x,y,v;
};
struct node{
    int mx;
    int pos;
    int l,r;
    int laz;
};
struct tree{
    vector<node> t;
    tree(int n) {t.resize(n*4);};

    void apply(int i,int val){
        t[i].mx+=val;
        t[i].laz+=val;
    }
    void push_up(int i){
        t[i].mx=max(t[i*2].mx,t[i*2+1].mx);
        t[i].pos=(t[i*2].mx>t[i*2+1].mx ? t[i*2].pos:t[i*2+1].pos);
    }

    void push_down(int i){
        if(t[i].laz==0) return;
        apply(i*2,t[i].laz);
        apply(i*2+1,t[i].laz);
        t[i].laz=0;
    }
    void build(const vector<int> &a,int i,int l,int r){
        t[i].l=l,t[i].r=r,t[i].laz=0;
        if(l==r){
            t[i].mx=a[l];
            t[i].pos=l;
            return;
        }
        int m=(l+r)/2;
        build(a,i*2,l,m);
        build(a,i*2+1,m+1,r);
        push_up(i);
    }
    void update(int i,int l,int r,int val){
        if(l<=t[i].l && t[i].r<=r){
            apply(i,val);
            return;
        }
        push_down(i);
        int m=(t[i].l+t[i].r)/2;
        if(l<=m) update(i*2,l,r,val);
        if(r>m) update(i*2+1,l,r,val);
        push_up(i);
    }
    pair<int,int> query(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            return {t[i].mx,t[i].pos};
        }
        push_down(i);
        int m=(t[i].l+t[i].r)/2;
        pair<int,int> res={-INT_MAX,-1};
        if(l<=m)  res=max(query(i*2,l,r),res);
        if(r>m)  res=max(query(i*2+1,l,r),res);
        return res;
    }
};

signed main(){
    int n;
    cin>>n;
    vector<point> a(n);
    vector<int> b;
    for(int i=0;i<n;i++){
        int x,y,v;
        cin>>x>>y>>v;
        if(x>y) swap(x,y);
        a[i].x=x;
        a[i].y=y;
        a[i].v=v;
        b.push_back(a[i].x);
        b.push_back(a[i].y);
    } 
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    int m=b.size();
    tree t(m);
    t.build(b,1,0,m-1);
    int x1=2e9,x2=2e9;
    sort(a.begin(),a.end(),[&](const point &p1,const point &p2){return p1.y<p2.y;});
    int ans=0;
    for(int i=0;i<n;){
        int y=a[i].y;
        int j=i;
        while(j<n && a[j].y==y){
            int xid=lower_bound(b.begin(),b.end(),a[j].x)-b.begin();
            t.update(1,0,xid,a[j].v);
            j++;
        }
        int idy=lower_bound(b.begin(),b.end(),y)-b.begin();
        auto res=t.query(1,0,idy);
        if(res.first-y>ans){
            ans=res.first-y;
            x1=b[res.second];
            x2=y;
        }       
        i=j;
    }
    cout<<ans<<'\n';
    cout<<x1<<" "<<x1<<" "<<x2<<" "<<x2<<'\n';
    system("pause");
    return 0;
}