#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21);

struct segt{
    int n;
    vector<int> t;

    segt(int nn):n(nn){
        t.assign(n*4,0);
    }

    void upd(int i,int l,int r,int pos,int val){
        if(r==l){
            t[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) upd(i*2,l,mid,pos,val);
        else upd(i*2+1,mid+1,r,pos,val);
        t[i]=max(t[i*2],t[i*2+1]);
    }

    void upd(int pos,int val){
        upd(1,1,n,pos,val);
    }

    int findle(int i,int l,int r,int k){
        if(t[i]<k) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=findle(i*2,l,mid,k);
        if(res!=-1){
            return res;
        }
        else{
            return findle(i*2+1,mid+1,r,k);
        }
    }

    int findle(int k){
        return findle(1,1,n,k);
    }

};

segt t(N);

void solve(){
    int n;
    cin>>n;

    set<int> st{0,2*N};

    auto insert=[&](int x){
        auto it=st.insert(x).first;
        int l=*prev(it);
        int r=*next(it);
        t.upd(l+1,x-l-1);
        t.upd(x+1,r-x-1);
    };
    auto erase=[&](int x){
        auto it=st.find(x);
        int l=*prev(it);
        int r=*next(it);
        t.upd(l+1,r-l-1);
        t.upd(x+1,0);
        st.erase(it);
    };

    for(int i=0;i<n;i++){
        int ps;
        cin>>ps;
        insert(ps);
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        char op;
        int x;
        cin>>op>>x;
        if(op=='+'){
            insert(x);
        }
        else if(op=='-'){
            erase(x);
        }
        else{
            cout<<t.findle(x)<<" ";
        }
    }
    cout<<'\n';

    for(int x:st){
        if(x<N){
            t.upd(x+1,0);
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    //system("pause");
    return 0;
}
