#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<pair<int,int>,vector<int>> mp;
    vector<vector<int>> t(n);
    vector<int> degree(n);
    for(int i=0;i<n-1;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
        degree[u]++;
        degree[v]++;
        mp[{u,v}]={x,y};
    }
    int l=1,r=n;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(degree[i]==1){
            q.push(i);
        }
    }
    vector<int> res(n);
    vector<int> vis(n,false);
    while(!q.empty()){
        int nd=q.front();
        q.pop();
        vis[nd]=1;
        for(int nx:t[nd]){
            if(vis[nx]) continue;
            int x=mp[{min(nd,nx),max(nd,nx)}][0],y=mp[{min(nd,nx),max(nd,nx)}][1];
            if(nd<nx){
                if(x>y){
                    res[nd]=r--;
                }
                else{
                    res[nd]=l++;
                }
            }
            else{
                if(x>y){
                    res[nd]=l++;
                }
                else{
                    res[nd]=r--;
                }
            }
            if(--degree[nx]==1){
                q.push(nx);
            }   
        }
    }
    for(int i=0;i<n;i++){
        if(res[i]==0) res[i]=l++;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}