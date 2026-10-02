#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> b(n+1,0);
    for(int i=0;i<k;i++){
        int x;cin>>x;
        b[x]=1;
    }
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int st=-1;
    for(int i=1;i<=n;i++)if(!b[i]){st=i;break;}    
    if(st==-1){
        cout<<"No"<<'\n';
        return;
    }
    
    vector<bool> vis(n+1,false);
    vector<vector<int>> res;
    
    queue<int> q;
    q.push(st);
    vis[st]=true;
  
    vector<int> seq;
    while(!q.empty()){
        int u=q.front();q.pop();
        seq.push_back(u);
        if(b[u]) continue;
        vector<int> invited;
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=true;
                invited.push_back(v);
                q.push(v);
            }
        }
        if(!invited.empty()){
            vector<int> tmp={u,(int)invited.size()};
            tmp.insert(tmp.end(),invited.begin(),invited.end());
            res.push_back(tmp);
        }
    }
    for(int i=1;i<=n;i++)if(!vis[i]){cout<<"No"<<'\n';return;}
    cout<<"Yes"<<'\n';
    cout<<res.size()<<'\n';
    for(auto& v:res){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<(i==v.size()-1?"":" ");
        }
        cout<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}