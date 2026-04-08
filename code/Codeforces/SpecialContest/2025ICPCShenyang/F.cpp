#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--,y--;

    vector<vector<pair<int,int>>> g(n);
    vector<pair<int,int>> e(m);
    vector<bool> use(m,false); 
    vector<bool> incy(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        e[i]={u,v};
    }

    for(auto near:g[x]){
        if(near.first==y){
            if(m==n-1){
                cout<<"No"<<'\n';
                return;
            }
            cout<<"Yes\n";
            int pos=near.second;
            vector<int> vis(n,0),fa(n,-1);
            vector<pair<int,int>> ans(m);
            queue<int> q;
            q.push(x);q.push(y);
            vis[x]=vis[y]=1;fa[x]=fa[y]=pos;
            int st=-1,l,r;
            while(q.size()){
                int u=q.front();q.pop();
                for(auto& edge:g[u]){
                    int v=edge.first,i=edge.second;
                    if(i==fa[u])continue;
                    if(vis[v]){st=i;l=e[i].first;r=e[i].second;break;}
                    vis[v]=1;fa[v]=i;ans[i]={v,u};q.push(v);
                }
                if(st!=-1)break;
            }
            if(st==-1){cout<<"No\n";return;}
            use[st]=true;
            ans[st]={r,l};
            auto deal=[&](int curr,bool update){
                while(1){
                    int p=fa[curr];use[p]=true;
                    int u=e[p].first,v=e[p].second;
                    vis[u]=vis[v]=2;
                    if(u==curr){
                        if(update)ans[p]={v,u};
                        curr=v;
                    }else{
                        if(update)ans[p]={u,v};
                        curr=u;
                    }
                    if(p==pos)break;
                }
            };
            deal(r,true);deal(l,false);
            queue<int> q2;
            for(int i=0;i<n;i++)if(vis[i]==2)q2.push(i);
            while(q2.size()){
                int u=q2.front();q2.pop();
                for(auto& edge:g[u]){
                    int v=edge.first,i=edge.second;
                    if(use[i])continue;
                    use[i]=true;ans[i]={v,u};q2.push(v);
                }
            }
            for(int i=0;i<m;i++)if(use[i])cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
            return; 
        }
    }

    cout<<"Yes"<<'\n';

    for(auto near:g[x]){
        cout<<near.first+1<<" "<<x+1<<'\n';
        use[near.second]=true;
    }
    for(auto near:g[y]){
        cout<<near.first+1<<" "<<y+1<<'\n';
        use[near.second]=true;
    }

    for(int i=0;i<m;i++){
        if(!use[i]){
            cout<<e[i].first+1<<" "<<e[i].second+1<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0; 
}