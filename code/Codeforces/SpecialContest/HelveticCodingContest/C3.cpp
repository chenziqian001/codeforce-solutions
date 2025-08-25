#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e6+5;
int dp[MAX_N];
vector<int> g[MAX_N];


void dfs1(int u,int fa){
    dp[u]=0;
    for(int v:g[u]){
        if(v==fa) continue;
        dfs1(v,u);
        dp[u]+=(dp[v]==0);
    }
}
void dfs2(int u,int fa){
    for(int v:g[u]){
        if(v==fa) continue;
        dp[v] += (dp[u] == (dp[v] == 0));
        dfs2(v,u);
    }
}


void solve(){
   
    int n,t;
    cin>>n>>t;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        dp[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(0,-1);
    dfs2(0,-1);

    while(t--){
        int x;
        cin>>x;
        x--;
        if(dp[x]) cout<<"Ron"<<'\n';
        else cout<<"Hermione"<<'\n';
    }
}

int main() {
   solve();
   system("pause");
   return 0;
}