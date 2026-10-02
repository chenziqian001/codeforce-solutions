#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> e;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e.push_back({u,v});
    }
    string res="";
    vector<vector<int>> g(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) continue;
            int u1=e[i].first,v1=e[i].second;
            int u2=e[j].first,v2=e[j].second;
            if(u1>v1) swap(u1,v1);
            if(u2>v2) swap(u2,v2);
            if(u1>u2){
                swap(u1,u2);
                swap(v1,v2);
            }
            if(u1<u2 && u2<v1 && v1<v2){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> c(m,-1);
    
    for(int i=0;i<m;i++){
        if(c[i]!=-1) continue;
        queue<int> q;
        q.push(i);
        c[i]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(c[v]==-1){
                    c[v]=c[u]^1;
                    q.push(v);
                }
                else{
                    if(c[v]!=c[u]^1){
                        cout<<"Impossible"<<'\n';
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(c[i]==1) res+='i';
        else res+='o';
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}