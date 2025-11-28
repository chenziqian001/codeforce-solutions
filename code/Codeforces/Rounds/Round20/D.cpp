#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;


int t[N*4];

void push_up(int i){
    t[i]=max(t[i*2],t[i*2+1]);
}

void upd(int i,int l,int r,int pos,int val){
    if(l==r){
        t[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) upd(i*2,l,mid,pos,val);
    else upd(i*2+1,mid+1,r,pos,val);
    push_up(i);
}

int find(int i,int l,int r,int ql,int qr,int val){
    if(l>qr || r<ql || t[i]<=val){
        return -1;
    }
    if(l==r) return l;

    int mid=(l+r)/2;
    int res=-1;

    if(ql<=mid){
        res=find(i*2,l,mid,ql,qr,val);
    }
    if(res==-1 && qr>mid){
        res=find(i*2+1,mid+1,r,ql,qr,val);
    }
    return res;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> op(n);
    vector<int> x(n);
    vector<int> y(n);

    for(int i=0;i<n;i++){
        cin>>op[i]>>x[i]>>y[i];
    }
    auto v=x;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    vector<set<int>> s(n,{-1});
    
    for(int i=0;i<n;i++){
        x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin();
        if(op[i]=="add"){
            s[x[i]].insert(y[i]);
            upd(1,0,n-1,x[i],*s[x[i]].rbegin());
        }
        else if(op[i]=="remove"){
            s[x[i]].erase(y[i]);
            upd(1,0,n-1,x[i],*s[x[i]].rbegin());
        }
        else{
            int X=find(1,0,n-1,x[i]+1,n-1,y[i]);
            if(X==-1){
                cout<<-1<<'\n';
            }
            else{
                cout<<v[X]<<" "<<*s[X].upper_bound(y[i])<<'\n';
            }
        }
    }

    //system("pause");

}
