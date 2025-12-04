#include <bits/stdc++.h>
using namespace std;


int n;


struct zxt{
    struct node{
        int ls,rs,val;
    };

    node t[32000006];
    int tr[32000006];
    int idx;
    
    int build(int node,int l,int r){
        node=++idx;
        if(l==r){
            cin>>t[node].val;
            return node;
        }
        int mid=(l+r)/2;
        t[node].ls=build(t[node].ls,l,mid);
        t[node].rs=build(t[node].rs,mid+1,r);
        return node;
    }

    int add(int &node){
        idx++;
        t[idx]=t[node];
        return idx;
    
    
    }


    int upd(int node,int l,int r,int pos,int val){
        node=add(node);
        if(l==r){
            t[node].val=val;
        }
        else{
            int mid=(l+r)/2;
            if(pos<=mid) t[node].ls=upd(t[node].ls,l,mid,pos,val);
            else t[node].rs=upd(t[node].rs,mid+1,r,pos,val);
        }
        return node;
    }

    int query(int node,int l,int r,int pos){
        if(l==r) return t[node].val;
        int mid=(l+r)/2;
        if(pos<=mid){
            return query(t[node].ls,l,mid,pos);
        }
        else return query(t[node].rs,mid+1,r,pos);
    }

}tt;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    tt.tr[0]=tt.build(0,1,n);

    for(int i=1;i<=q;i++){
        int v,op;
        cin>>v>>op;
        if(op==1){
            int pos,val;
            cin>>pos>>val;
            tt.tr[i]=tt.upd(tt.tr[v],1,n,pos,val);
        }
        else{
            int pos;
            cin>>pos;
            cout<<tt.query(tt.tr[v],1,n,pos)<<'\n';
            tt.tr[i]=tt.tr[v];
        }
    }

    //system("pause");
    return 0;


}