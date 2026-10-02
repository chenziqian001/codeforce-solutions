#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> g(n+1); 
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({w,v});
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end(),[&](pair<int,int> x,pair<int,int> y){
            if(x.first!=y.first){
                return x.first>y.first;
            }
            else return x.second<y.second;
        });
    }


    int k;
    cin>>k;
   
    vector<bool> vis(n+1,false);
    
    while(k--){
        int node;
        cin>>node;
        while(true){
            vis[node]=true;
            cout<<node;
            bool ok=false; 
            for(auto p:g[node]){
                if(vis[p.second]){
                    continue;
                }
                else{
                    ok=true;
                    node=p.second;
                    cout<<"->";
                    break;
                }
            }
            if(!ok) break;
        }
        vis.assign(n+1,false);
        cout<<'\n';
    }
    



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