#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;

void solve(){
    int n,s1,s2;
    cin>>n>>s1>>s2;
    vector<vector<int>> e1(n);
    vector<vector<int>> e2(n);
    s1--,s2--;    
    int m1;
    cin>>m1;
    vector<vector<int>> con1(n,vector<int>(n));
    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        con1[u][v]=1;
        con1[v][u]=1;
        e1[v].push_back(u);
        e1[u].push_back(v);
    }
    
    int m2;
    cin>>m2;
    vector<vector<int>> con2(n,vector<int>(n));
    for(int i=0;i<m2;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        con2[u][v]=1;
        con2[v][u]=1;
        e2[u].push_back(v);
        e2[v].push_back(u);
    }

    set<int> good;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(con1[i][j]==1 && con2[i][j]==1){
                good.insert(i);
                good.insert(j);
            }
        }
    }
    vector<vector<int>> dis(n,vector<int>(n,inf));
    dis[s1][s2]=0;
    
    auto cmp=[&](const pair<int,int>& x,const pair<int,int>& y){
        return dis[x.first][x.second]>dis[y.first][y.second];
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    pq.push({s1,s2});
    while(!pq.empty()){
        auto [u1,u2]=pq.top();
        pq.pop();
        int d=dis[u1][u2];
        for(int v1:e1[u1]){
            for(int v2:e2[u2]){
                int cost=abs(v1-v2);
                if(d+cost<dis[v1][v2]){
                    dis[v1][v2]=d+cost;
                    pq.push({v1,v2});
                }
            }
        }

    }
    int res=inf;
    for(int x:good){
        res=min(res,dis[x][x]);
    }
    if(res==inf){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';

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