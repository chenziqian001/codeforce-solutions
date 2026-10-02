#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<vector<pair<int,int>>>g(n+1);
    vector<int>deg(n+1),dep(n+1),b(n+1),eg(n+1);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        deg[u]++;deg[v]++;
    }
    int rt=1;
    for(int i=1;i<=n;i++)if(deg[i]>2)rt=i;
    vector<set<int>>s(n+1);
    auto dfs=[&](auto&&self,int node,int fa,int br)->void{
        for(auto p:g[node]){
            int next=p.first,id=p.second;
            if(next==fa)continue;
            dep[next]=dep[node]+1;
            b[next]=br?br:next;
            eg[id]=next;
            self(self,next,node,b[next]);
        }
    };
    dfs(dfs,rt,0,0);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int tp;cin>>tp;
        if(tp==1){
            int id;cin>>id;
            s[b[eg[id]]].erase(dep[eg[id]]);
        }else if(tp==2){
            int id;cin>>id;
            s[b[eg[id]]].insert(dep[eg[id]]);
        }else{
            int u,v;cin>>u>>v;
            if(u==v)cout<<0<<'\n';
            else if(b[u]==b[v]&&u!=rt&&v!=rt){
                int x=min(dep[u],dep[v]),y=max(dep[u],dep[v]);
                auto it=s[b[u]].upper_bound(x);
                if(it!=s[b[u]].end()&&*it<=y)cout<<-1<<'\n';
                else cout<<y-x<<'\n';
            }else{
                int ok=1;
                if(u!=rt){
                    auto it=s[b[u]].begin();
                    if(it!=s[b[u]].end()&&*it<=dep[u])ok=0;
                }
                if(v!=rt){
                    auto it=s[b[v]].begin();
                    if(it!=s[b[v]].end()&&*it<=dep[v])ok=0;
                }
                if(!ok)cout<<-1<<'\n';
                else cout<<dep[u]+dep[v]<<'\n';
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    //system("pause");
    return 0;
}