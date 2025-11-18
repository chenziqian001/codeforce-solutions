#include<bits/stdc++.h>
using namespace std;
#define data info
string s;

struct info{
    int c0,c1,c01,c10;
};

struct node{
    int l,r;
    data d;
    bool flip;
};

struct segt{
    vector<node> t;
    segt(int n){
        t.resize(n*4);
    }

    data mergeinfo(const data &a ,const data &b){
        data c;
        c.c0=a.c0+b.c0;
        c.c1=a.c1+b.c1;
        c.c01=max(a.c01+b.c1,a.c0+b.c01);
        c.c10=max(a.c1+b.c10,a.c10+b.c0);
        return c;
    }

    void fl(int i){
        node &nd=t[i];
        data d=nd.d;
        nd.d={d.c1,d.c0,d.c10,d.c01};
        nd.flip^=1;
    }

    void build(int i,int l,int r){
        t[i].l=l;
        t[i].r=r;
        t[i].flip=false;
        if(l==r){
            t[i].d.c1=(s[l-1]=='7');
            t[i].d.c0=(s[l-1]=='4');
            t[i].d.c01=t[i].d.c10=1;
            return;
        }
        int mid=(l+r)>>1;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        t[i].d=mergeinfo(t[i*2].d,t[i*2+1].d);
    }


    void push_down(int i){
        if(t[i].flip){
            fl(i*2);
            fl(i*2+1);
            t[i].flip=false;
        }
    }
    void upd(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            fl(i);
            return;
        }
        push_down(i);
        int mid=(t[i].l+t[i].r)/2;
        if(l<=mid) upd(i*2,l,r);
        if(r>mid) upd(i*2+1,l,r);
        t[i].d=mergeinfo(t[i*2].d,t[i*2+1].d);
    }
};
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s;

    segt st(n);
    st.build(1,1,n);

    while(m--){
        string op;
        cin>>op;

        if(op=="count"){
            cout<<st.t[1].d.c01<<'\n';
        }
        else{
            int l,r;
            cin>>l>>r;
            st.upd(1,l,r);
        }


    }

    //system("pause");
    return 0;
}
