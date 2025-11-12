#include<bits/stdc++.h>
using namespace std;
#define int long long
int basis[64];
void insert(int x){
    for(int i=63;i>=0;i--){
        if((x>>i)&1){
            if(!basis[i]){
                basis[i]=x;
                return;
            }
            x^=basis[i];
        }
    }
}

int query(int res=0){
    for(int i=63;i>=0;i--){
        if((res^basis[i])>res){
            res^=basis[i];
        }
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<int> vis(n);
    vector<int> val(n);
    function<void(int,int)> dfs=[&](int node,int v){
        vis[node]=1;
        val[node]=v;
        for(auto [next,w]:g[node]){
            if(vis[next]){
                insert(w^v^val[next]);
            }
            else{
                dfs(next,v^w);
            }
        }
    };
    dfs(0,0);
    cout<<query(val[n-1])<<'\n';
    //system("pause");
}

