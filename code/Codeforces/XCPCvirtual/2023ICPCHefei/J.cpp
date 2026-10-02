#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct E{
    int v,w;
    bool operator>(const E& o)const{return w>o.w;}
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<E>> g(n+1);
    vector<int> U(m),V(m),W(m);
    for(int i=0;i<m;i++){
        cin>>U[i]>>V[i]>>W[i];
        g[U[i]].push_back({V[i],W[i]});
        g[V[i]].push_back({U[i],W[i]});
    }

    auto dij=[&](int s){
        vector<int> d(n+1,2e9+7);
        priority_queue<E,vector<E>,greater<E>> q;
        d[s]=0;
        q.push({s,0});
        while(!q.empty()){
            auto [u,cw]=q.top();
            q.pop();
            if(cw>d[u]) continue;
            for(auto& e:g[u]){
                int nw=max(cw,e.w);
                if(nw<d[e.v]){
                    d[e.v]=nw;
                    q.push({e.v,nw});
                }
            }
        }
        return d;
    };
    vector<int> d1=dij(1);
    vector<int> dn=dij(n);
    
    int res=4e18;
    for(int i=0;i<m;i++){
        int u=U[i],v=V[i],w=W[i];
        if(w>=max(d1[u],dn[v])) res=min(res,w+max(d1[u],dn[v]));
        if(w>=max(d1[v],dn[u])) res=min(res,w+max(d1[v],dn[u]));
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}