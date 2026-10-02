#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r,id;
};
bool cmpl(node x,node y){
    if(x.l==y.l) return x.r>y.r;
    else return x.l<y.l;
}
bool cmpr(node x,node y){
    return x.r>y.r;
}
void solve(){
    int n,f;
    cin>>n>>f;
    vector<node> a(n+1);
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i].l=x,a[i].r=y,a[i].id=i;  
    }
    vector<int> ans(n);
    int cnt=0;
    sort(a.begin()+1,a.end(),cmpl);
    int now=f;
    long long res=0;
    for(int i=1;i<=n;i++){
        int l=a[i].l,r=a[i].r;
        if(l<=now){
            if(r>now){
                res+=(r-l);
                now=r;
                vis[a[i].id]=true;
                ans[cnt++]=a[i].id;
            }
        }
        else{
            res+=l-now;
            res+=(r-l);
            now=r;
            vis[a[i].id]=true;
            ans[cnt++]=a[i].id;
        }
    }
    sort(a.begin()+1,a.end(),cmpr);
    for(int i=1;i<=n;i++){
        if(!vis[a[i].id]){
            res+=(a[i].r-a[i].l);
            ans[cnt++]=a[i].id;
        }
    }
    cout<<res<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}