#include<bits/stdc++.h>
using namespace std;
#define int long long

struct bais{
    int bit[40];
    bais() { memset(bit , 0 , sizeof bit); }

    void upd(int x){
        for(int i=31;i>=0;i--){
            if(((x>>i)&1)==0) continue;
            if(!bit[i]){
                bit[i]=x;
                return;
            }
            x^=bit[i];
        }
    }

    int query(){
        int res=0;
        for(int i=31;i>=0;i--){
            if((res^bit[i])>res){
                res^=bit[i];
            }
        }
        return res;
    }



    void merge(bais other){
        for(int i=31;i>=0;i--){
            if(other.bit[i]!=0){
                upd(other.bit[i]);
            }
        }
    }
};

struct node{
    int l,r;
    bais info;
};

struct segt{
    vector<node> t;


    segt(int n){
        t.resize(n<<2);
    }

    void push_up(int i){
        t[i].info.merge(t[i*2].info);
        t[i].info.merge(t[i*2+1].info);
    }


    void build(int i,int l,int r){
        t[i].l=l,t[i].r=r;
        if(l==r) return;

        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
    }

    void upd(int i,int pos,int val){
        if(t[i].l==t[i].r){
            t[i].info.upd(val);
            return;
        }
        int mid=(t[i].l+t[i].r)/2;

        if(pos<=mid){
            upd(i*2,pos,val);
        }
        else{
            upd(i*2+1,pos,val);
        }
        push_up(i);
    }

    bais find(int i,int l,int r){
        if(l<=t[i].l && t[i].r<=r){
            return t[i].info;
        }
        int mid=(t[i].l+t[i].r)/2;
        bais res;
        if(l<=mid){
            res.merge(find(i*2,l,r));
        }
        if(r>mid){
            res.merge(find(i*2+1,l,r));
        }
        return res;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    segt st(m);

    st.build(1,1,m);


    for(int i=0;i<n;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            st.upd(1,x,y);
        }
        else{
            int res=st.find(1,x,y).query();
            cout<<res<<'\n';
        }
    }
    //system("pause");


}