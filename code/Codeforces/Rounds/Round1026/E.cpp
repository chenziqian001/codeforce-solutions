#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> v(n+1),p(n+1);
    vector<int> vv,pp;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>p[i];
        vv.push_back(v[i]);
        pp.push_back(p[i]);
    }
    
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    sort(pp.begin(),pp.end());
    pp.erase(unique(pp.begin(),pp.end()),pp.end());
    int tt=vv.size()+pp.size();
    vector<vector<pair<int,int>>> adj(tt+10);
    for(int i=1;i<=n;i++){
        v[i]=lower_bound(vv.begin(),vv.end(),v[i])-vv.begin();
        p[i]=lower_bound(pp.begin(),pp.end(),p[i])-pp.begin()+vv.size();
        adj[v[i]].push_back({p[i],i});
        adj[p[i]].push_back({v[i],i});
    }

    
    int odd=0;
    int st=-1;
    for(int i=0;i<tt;i++){
        if(adj[i].size()%2) odd++;
        if(adj[i].size()) st=i;
    }

    if(st==-1 || odd>2){
        cout<<"NO"<<'\n';
        return;
    }

    queue<int> q;
    vector<int> vis(tt);
    vis[st]=1;
    q.push(st);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto [next,id]:adj[node]){
            if(!vis[next]){
                vis[next]=1;
                q.push(next);
            }
        }
    }

    for(int i=0;i<tt;i++){
        if(adj[i].size() && !vis[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }


    vector<bool> used(n+1);
    vector<int> path;
    vector<int> del(tt);

    auto dfs=[&](auto dfs,int node)->void{
        for(int &i=del[node];i<adj[node].size();i++){
            auto [next,id]=adj[node][i];
            if(used[id]) continue;
            used[id]=1;
            dfs(dfs,next);
            path.push_back(id); 
        }
    };
    
    for(int i=0;i<tt;i++){
        if(adj[i].size()%2){
            st=i;
            break;
        }
    }

    dfs(dfs,st);
    cout<<"YES"<<'\n';
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<'\n';
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