#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok=false;
    int node=-1;
    for(int i=1;i<=n;i++){
        if(g[i].size()==2){
            ok=true;
            node=i;
            break;
        }
    }
    if(!ok){
        cout<<"NO"<<'\n';
        return;
    }
    else{
        cout<<"YES"<<'\n';
        vector<array<int,2>> ans;
        int a=g[node][0],b=g[node][1];
        if(g[a].size()>g[b].size()) swap(a,b);
        ans.push_back({a,node});
        ans.push_back({node,b});
        function<void(int,int,int)> dfs;
        dfs=[&](int pos,int status,int prev){
            for(int next:g[pos]){
                if(next==prev) continue;
                if(status){
                    ans.push_back({pos,next});
                    dfs(next,1-status,pos);
                }
                else{
                    ans.push_back({next,pos});
                    dfs(next,1-status,pos);
                }
            }
            return;
        };
        dfs(a,1,node);
        dfs(b,0,node);
        for(auto an:ans){
            cout<<an[0]<<" "<<an[1]<<'\n';
        }
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}