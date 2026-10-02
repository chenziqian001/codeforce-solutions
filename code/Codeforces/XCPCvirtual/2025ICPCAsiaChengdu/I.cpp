#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int cnt[N];
int n,q;
struct node{
    int l,r,t;
} tr[N<<2];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void build(int i,int l,int r){
    tr[i]={l,r,0};
    if(l!=r){
        int mid=(l+r)/2;
        build(i<<1,l,mid);
        build(i<<1|1,mid+1,r);       
    }
}
void push_up(int u){
    tr[u].t=gcd(tr[u<<1].t,tr[u<<1|1].t);
}
void modify(int i,int pos,int val){
    if(tr[i].l==tr[i].r)  tr[i].t=val;
    else{
        int mid=(tr[i].l+tr[i].r)/2;
        if(pos<=mid) modify(i<<1,pos,val);
        else modify(i<<1|1,pos,val);
        push_up(i);
    }
}

void solve(){
    cin>>n>>q;
    build(1,1,n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]) modify(1,i,i);
        else modify(1,i,0);
    }
    int ans=tr[1].t;
    if(ans==0) cout<<n<<'\n';
    else cout<<cnt[ans]<<'\n';
    
    while(q--){
        int p,v;
        cin>>p>>v;
        a[p]=v;
        if(a[p-1]>a[p]) modify(1,p-1,p-1);
        else modify(1,p-1,0);
        if(p+1<=n){
            if(a[p]>a[p+1]) modify(1,p,p);
            else modify(1,p,0);
        }
        int tmp=tr[1].t;
        if(tmp==0) cout<<n<<'\n';
        else cout<<cnt[tmp]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i=1;i<=200001;i++){
        for(int j=1;j*i<=200001;j++) cnt[i*j]++;
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}