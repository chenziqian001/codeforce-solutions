#include<bits/stdc++.h>
using namespace std;
 
#define int long long

struct E{
    int u,v,w;
    bool operator<(const E& o) const{
        return w>o.w;
    }
};

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n+1);
        for(int i=0;i<=n;i++) fa[i] = i;
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx == fy) return false;
        fa[fx] = fy;
        return true;
    }
};



void solve(){
    int m,n;
    cin>>m>>n;
    vector<int> a(m+1),b(n+1);
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<E> e;
    int res=0;
    for(int i=1;i<=m;i++){
        int s;
        cin>>s;
        for(int j=0;j<s;j++){
            int x;
            cin>>x;
            e.push_back({i,m+x,a[i]+b[x]});
            res+=a[i]+b[x];
        }
    }
    sort(e.begin(),e.end());
    DSU dsu(m+n);
    for(auto p:e){
        if(dsu.merge(p.u,p.v)){
            res-=p.w;
        }
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