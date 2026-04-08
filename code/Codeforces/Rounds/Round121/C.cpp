#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }

    vector<vector<int>> pa(n,vector<int>(20));
    vector<int> d(n);

    auto dfs1=[&](auto&&self,int node,int fa)->void{
        pa[node][0]=fa;
        for(int i=1;i<20;i++){
            pa[node][i]=pa[pa[node][i-1]][i-1];
        }
        for(auto e:g[node]){
            if(e.first==fa) continue;
            d[e.first]=d[node]+1;
            self(self,e.first,node);
        }
    };
    dfs1(dfs1,0,0);

    auto lca=[&](int u,int v){
        if(d[u]<d[v]) swap(u,v);
        for(int i=19;i>=0;i--) if(d[u]-(1<<i)>=d[v]) u=pa[u][i];
        if(u==v) return u;
        for(int i=19;i>=0;i--) if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i];
        return pa[u][0];
    };


    int k;
    cin>>k;
    vector<int> val(n);
    vector<int> a(n-1);
    while(k--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        val[u]++;
        val[v]++;
        val[lca(u,v)]-=2;
    }

    auto dfs2=[&](auto&&self,int node,int fa)->int{
        int sum=val[node];
        for(auto e:g[node]){
            if(e.first==fa) continue;
            int ex=self(self,e.first,node);
            a[e.second]=ex;
            sum+=ex;
        }
        return sum;
    };
    dfs2(dfs2,0,0);
    for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
    cout<<'\n';
    
    //system("pause");

}


 