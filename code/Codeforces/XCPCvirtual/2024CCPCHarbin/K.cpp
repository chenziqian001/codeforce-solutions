#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int w,l,r;
    bool operator<(const node o) const{
        return w>o.w;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<node> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].l>>a[i].r;
    sort(a.begin()+1,a.end());
    vector<int> sl(n+2),sr(n+2),swl(n+2),swr(n+2),delta(n+2);

    for(int i=1;i<=n;i++){
        sl[i]=sl[i-1]+a[i].l;
        sr[i]=sr[i-1]+a[i].r;
        swl[i]=swl[i-1]+a[i].w*a[i].l;
        swr[i]=swr[i-1]+a[i].w*a[i].r;
        delta[i]=delta[i-1]+(a[i].r-a[i].l);
    }
    int res=0,base=0,re=m-sl[n];
    for(int i=1;i<=n;i++){
        int add=min(re,a[i].r-a[i].l);
        base+=a[i].w*(a[i].l+add);
        re-=add;
    }
    res=base;
    for(int i=1;i<=n;i++){
        int cur=m-sr[i-1]-(sl[n]-sl[i]);
        if(cur<0){
            int rem=m-sl[n]+a[i].l;
            int idx=upper_bound(delta.begin()+1,delta.begin()+n+1,rem)-delta.begin()-1;
            int left=rem-delta[idx];
            int profit=swr[idx]+a[idx+1].w*(a[idx+1].l+left)+(swl[n]-swl[idx+1])-a[i].w*a[i].l;
            res=max(res,profit);
            continue;
        }
        res=max(res,swr[i-1]+(swl[n]-swl[i])+a[i].w*cur);
    }
    cout<<res<<'\n';
   


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}


