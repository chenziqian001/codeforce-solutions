#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct Edge{int v,w;};
vector<Edge> g[N];
int dis[N],n,m;
struct node{
  int u,d;
  bool operator>(const node& r)const{return d>r.d;} // 堆优化：小根堆
};
// 1. 初始化dis为1e18
// 2. 堆中存储 {u, d}, 满足 d > dis[u] 则跳过 (懒惰删除)
void dijkstra(int s){
  priority_queue<node,vector<node>,greater<node>> q;
  for(int i=1;i<=n;i++)dis[i]=1e18; 
  dis[s]=0;q.push({s,0});
  while(!q.empty()){
    node f=q.top();q.pop();
    int u=f.u,d=f.d;
    if(d>dis[u])continue;
    for(auto e:g[u])if(dis[e.v]>dis[u]+e.w){
      dis[e.v]=dis[u]+e.w;
      q.push({e.v,dis[e.v]});
    }
  }
}
int32_t main(){
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0,u,v,w;i<m;i++)cin>>u>>v>>w,g[u].push_back({v,w});
  dijkstra(1);
  return 0;
}