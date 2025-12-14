#include<bits/stdc++.h>
using namespace std;
#define int long long


struct Data{
    int l,r;
    int pre;
    int suf;
    int res;
};


Data merge(const Data &ls,const Data &rs){
    Data d;
    d.l=ls.l;
    d.r=rs.r;
    d.pre=ls.pre;
    if(ls.pre==ls.r-ls.l+1){
        d.pre+=rs.pre;
    }
    d.suf=rs.suf;
    if(rs.suf==rs.r-rs.l+1){
        d.suf+=ls.suf;
    }

    d.res=ls.res+rs.res-(ls.suf+1)/2-(rs.pre+1)/2+(ls.suf+rs.pre+1)/2;
    return d;
}

vector<Data> tree;

void build(int i,int l,int r){
    tree[i].l=l;
    tree[i].r=r;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void upd(int i,int pos,int val){
    Data& cur=tree[i];
    if(cur.l==cur.r){
        cur.pre=val;
        cur.suf=val;
        cur.res=val;
        return;
    }
    int mid=(cur.l+cur.r)/2;
    if(pos<=mid){
        upd(i*2,pos,val);
    }
    else{
        upd(i*2+1,pos,val);
    }
    tree[i]=merge(tree[i*2],tree[i*2+1]);
}






signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,i};
    }   

    sort(a.begin(),a.end(),[&](pair<int,int> &x,pair<int,int> &y){
        return  x.first<y.first;
    });

    tree.resize(n*4);
    build(1,0,n-1);

    int res=1e18;
    int l=0;

    for(int r=0;r<n;r++){
        upd(1,a[r].second,1);
        while(tree[1].res>=m){
            res=min(res,a[r].first-a[l].first);
            upd(1,a[l].second,0);
            l++;
        }
    }


    cout<<res<<'\n';
    //system("pause");
    return 0;
}