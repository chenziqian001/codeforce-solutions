#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        w=w^1;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    } 

    vector<int> c(n,-1);
    vector<int> res;
    for(int i=0;i<n;i++){
        if(c[i]==-1){
            queue<int> q;
            q.push(i);
            c[i]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(c[u]==1){
                    res.push_back(u);
                }
                for(auto p:g[u]){
                    int v=p.first;
                    int w=p.second;
                    if(c[v]==-1){
                        c[v]=c[u]^w;
                        q.push(v);
                    }
                    else{
                        if(c[v]!=(c[u]^w)){
                            cout<<"Impossible"<<'\n';
                            return;
                        }
                    }
                }
            }
        }
    }
    cout<<res.size()<<'\n';
    for(int x:res){
        cout<<x+1<<" ";
    }
    cout<<'\n';




}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;

}


 