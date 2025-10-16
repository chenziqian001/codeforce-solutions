#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t[(N<<2)+10];
int laze[(N<<2)+10];
int res;
void build(int id,int l,int r){
    if(l==r){
        t[id]=-(l+1);
        laze[id]=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}

void push_down(int id){
    t[id*2]+=laze[id];
    t[id*2+1]+=laze[id];
    laze[id*2]+=laze[id];
    laze[id*2+1]+=laze[id];
    laze[id]=0;
}

void add(int id,int l,int r,int L,int R,int val){
    if(L>R)return;
	if(L<=l&&r<=R){
	    t[id]+=val; laze[id]+=val; return;
	}
	push_down(id);
    int md=(l+r)/2;
	if(L<=md)add(id*2,l,md,L,R,val);
	if(R>md)add(id*2+1,md+1,r,L,R,val);
	t[id]=min(t[id*2],t[id*2+1]);

}

void get(int id,int l,int r){
	if(t[id]>=0){
		res=max(res,r+1); return;
	}
	if(l==r)return;
		
	push_down(id);
    int mid=(l+r)/2;
    if(t[id*2]>=0){
		res=max(res,mid+1); get(id*2+1,mid+1,r);
	}
	else{
		get(id*2,l,mid);
	}
}
int main(){
    int ac,dr;
    cin>>ac>>dr;
    int n;
    cin>>n;
    build(1,0,n-1);
    vector<int> a(n);
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>d[i];
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=max(a[i]-ac,0)+max(d[i]-dr,0);
    for(int i=0;i<n;i++) add(1,0,n-1,p[i],n-1,1);
    res=0;
    int m;
    cin>>m;
    while(m--){
        int k,na,nd;
        cin>>k>>na>>nd;
        k--;
        add(1,0,n-1,p[k],n-1,-1);
        p[k]=max(na-ac,0)+max(nd-dr,0);
        add(1,0,n-1,p[k],n-1,1);
        res=0;
        get(1,0,n-1);
        cout<<res<<'\n';
    }
    return 0;
}