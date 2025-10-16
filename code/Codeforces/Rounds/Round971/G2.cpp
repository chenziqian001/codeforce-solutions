#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5;
multiset<int> s;
struct node{
    int l,r;
    int sum,f;
}tr[N*4];
struct qr{
    int l,r,id;
};
void push_up(int id){
    tr[id].sum=(tr[id*2].sum+tr[id*2+1].sum);
}
void build(int id,int l,int r){
    if(l==r){
        tr[id]={l,r,0,-1};
        return;
    }
    tr[id]={l,r,0,-1};
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    push_up(id);
}
void push_down(int id){
    node &root=tr[id],&ls=tr[id*2],&rs=tr[id*2+1];
    if(root.f!=-1){
        ls.sum=(ls.r-ls.l+1LL)*root.f;
        ls.f=root.f;
        rs.sum=(rs.r-rs.l+1LL)*root.f;
        rs.f=root.f;
        root.f=-1;
    }
}

void modify(int id,int l,int r,int val){
    if(tr[id].l>=l && tr[id].r<=r){
        tr[id].sum=(tr[id].r-tr[id].l+1LL)*val;
        tr[id].f=val;
        return;
    }
    push_down(id);
    int mid=(tr[id].l+tr[id].r)/2;
    if(l<=mid) modify(id*2,l,r,val); 
    if(r>mid) modify(id*2+1,l,r,val);
    push_up(id);
}
void add(int x,int y,vector<int> &num){
    if(num[x]) s.erase(s.find(num[x]));
    num[x]+=y;
    if(num[x])s.insert(num[x]);
}
int ask(int id,int l,int r){
    if(tr[id].l>=l && tr[id].r<=r) return tr[id].sum;
    push_down(id);
    int res=0;
    int mid=(tr[id].l+tr[id].r)>>1;
    if(l<=mid) res+=ask(id*2,l,r);
    if(r>mid) res+=ask(id*2+1,l,r);
    return res;
}
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    s.clear();
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x-i+n;
    }
    vector<int> num(n*8+10);
    vector<int> f(n);
    for(int i=0;i<n;i++){
        if(i>=k) add(a[i-k],-1,num);
        add(a[i],1,num);
        if(i>=k-1)f[i-k+1]=k-*s.rbegin();
    }
    vector<qr> query(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;

        query[i]={l,r,i};
    }    
    sort(query.begin(),query.end(),[&](auto a,auto b){
        return a.l>b.l;
    });
    int p=0;
    int tt=0;
    int ed=n-k;
    build(1,0,ed);
    vector<int> stk(n);
    vector<int> ans(q);
    for(int i=ed;i>=0;i--){
        while(tt &&f[stk[tt-1]]>=f[i]) tt--;
        if(tt) modify(1,i,stk[tt-1]-1,f[i]);
        else modify(1,i,ed,f[i]);
        while(p<(int)query.size() && query[p].l==i){
            ans[query[p].id]=ask(1,query[p].l,query[p].r-k+1);
            p++;
        }
        stk[tt++]=i;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}