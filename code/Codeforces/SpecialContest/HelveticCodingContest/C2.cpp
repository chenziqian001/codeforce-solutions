#include<bits/stdc++.h>
using namespace std;
int rt;
bool dfs(const vector<vector<int>>& g,int node,int pa){
    if (g[node].size() == 1 && node != rt) { 
        return false; 
    }
    bool res=true;
    for(int next:g[node]){
        if(next==pa) continue;
        res=res&&dfs(g,next,node);
    }
    return !res;
}
void solve(){
    int n,t;
    cin>>n>>t;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);        
    }
    cin>>rt;
    rt--;
    bool is_Ron_win=true&&dfs(g,rt,-1);
    if(is_Ron_win) cout<<"Ron"<<'\n';
    else cout<<"Hermione"<<'\n';
}
int main(){
    solve();
    system("pause");
    return 0;
}