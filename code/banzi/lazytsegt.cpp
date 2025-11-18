#include<bits/stdc++.h>
using namespace std;


struct node{
    int l,r;
    int val,tag;
};

struct segt{
    vector<node> t;
    segt(int n){
        t.resize(n*4);
    }

    void push_up(int i){
        t[i].val=max(t[i<<1].val,t[i<<1|1].val);
    }

    void apply(int i,int v){
        t[i].val+=v;
        t[i].tag+=v;
    }

    void build(vector<int> &a,int i,int l,int r){
        t[i].l=l,t[i].r=r;
        t[i].tag=0;
        if(l==r){
            t[i].val=a[l-1];
            return;
        }
        int mid=(l+r)/2;
        build(a,i*2,l,mid);
        build(a,i*2+1,mid+1,r);
        push_up(i);
    }

    void push_down(int i){
        if(t[i].tag){
            apply(i*2,t[i].tag);
            apply(i*2+1,t[i].tag);
            t[i].tag=0;
        }
    }

    void upd(int i,int l,int r,int v){
        if(l<=t[i].l && t[i].r<=r){
            apply(i,v);
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(l<=mid) upd(i*2,l,r,v);
        if(r>mid) upd(i*2+1,l,r,v);
        push_up(i);
    }


    int query(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            return t[i].val;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(r<=mid) return query(i<<1,l,r);
        if(l>mid) return query(i<<1|1,l,r);
        return max(query(i*2+1,l,r),query(i*2,l,r));
    }
};