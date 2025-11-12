#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    int a,b;
    cin>>a>>b;
    a--,b--;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    vector<int> pa(n);
    function<void(int,int)> dfs1=[&](int node,int fa){
        for(int next:t[node]){
            if(next==fa) continue;
            pa[next]=node;
            dfs1(next,node);
        }
    };
    dfs1(b,-1);
    vector<int> path;
    int v=a;
    while(v!=b){
        path.push_back(v);
        v=pa[v];
    }
    path.push_back(b);


    int m=path.size();
    int root=path[(m-1)/2];

    int mx=0;
    function<void(int,int,int)> dfs2=[&](int node,int fa,int dep){
        if(dep>mx) mx=dep;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs2(next,node,dep+1);
        }
    };
    dfs2(root,-1,0);
    cout<<2*(n-1)-mx+m/2<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}