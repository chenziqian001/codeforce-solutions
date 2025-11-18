#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    map<pair<int,int>,set<int>> bad;
    for(int i=0;i<k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        bad[{x,y}].insert(z);
    }

    vector<vector<int>> dis(n+1,vector<int>(n+1,inf));
    dis[0][1]=0;
    vector<vector<pair<int,int>>> pp(n+1,vector<pair<int,int>>(n+1));
    pp[0][1]={-1,-1};

    queue<pair<int,int>> q;
    q.emplace(0,1);


    while(!q.empty()){
        auto [pre,cur]=q.front();
        q.pop();

        for(int next:g[cur]){
            if(bad.find({pre,cur})!=bad.end() && bad[{pre,cur}].count(next)) continue;
            if(dis[cur][next]==inf){
                dis[cur][next]=dis[pre][cur]+1;
                pp[cur][next]={pre,cur};
                q.emplace(cur,next);
            }
        }
    }
    
    int res=inf;
    int minip;
    
    for(int prev:g[n]){
        if(dis[prev][n]!=inf){
            if(dis[prev][n]<res){
                minip=prev;
                res=dis[prev][n];
            }
            
        }
    }

    if(res==inf){
        cout<<-1<<'\n';
        return 0;
    }
    else cout<<res<<'\n';

    vector<int> path;
    int u=minip;
    int v=n;
    while(u!=-1 && v!=-1){
        path.push_back(v);
        auto t=pp[u][v];
        u=t.first;
        v=t.second;
    }

    reverse(path.begin(),path.end());

    for(int x:path){
        cout<<x<<" ";
    }
    



    //system("pause");

}
