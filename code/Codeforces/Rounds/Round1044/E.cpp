#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> deg(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    vector<int> col(n,-1);
    vector<pair<int,int>> ans;
    vector<int> vis(n);
    function<void(int,int)> dfs1=[&](int node,int fa){
        int cnt=0;
        bool ok=false;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs1(next,node);
            if(col[next]==0) cnt++;
            if(col[next]==1) ok=true;
        }
        if(cnt>=3 || ok){
            col[node]=2;
            ans.emplace_back(2,node);deg[node]--;
            for(int next:t[node]){
                deg[next]--;
            }
        }
        else if(cnt==2){
            col[node]=1;
        }
        else if(cnt<=1){
            col[node]=0;
        }
        
    };
    dfs1(0,-1);
    function<void(int)> dfs2=[&](int node){
        ans.emplace_back(1,node);
        vis[node]=1;
        for(int next:t[node]){
            if(vis[next]) continue;
            if(col[next]==2) continue; 
            dfs2(next);
        }
    };
    for(int i=0;i<n;i++){
        if(!vis[i] && col[i]==2){
            vis[i]=1;
            ans.emplace_back(1,i);
        }
    }
    

    for(int i=0;i<n;i++){
        if(!vis[i] && col[i]==0 && deg[i]<=1){
            dfs2(i);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto [op,node]:ans){
        cout<<op<<" "<<node+1<<'\n';
    }
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
/*
1
5
1 5
1 4
4 3
4 2
*/