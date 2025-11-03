#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    double res=0;
    function<void(int,int,int)> dfs=[&](int node,int fa,int dep){
        res+=1.0/(dep+1);
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node,dep+1);
        }
    };

    dfs(0,-1,0);
    cout<<fixed<<setprecision(10)<<res<<'\n';
    return 0;
}