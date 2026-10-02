#include<bits/stdc++.h>
using namespace std;
const int N=114514;

int dfn[N],low[N],stk[N],top,tot; // dfn:发现时间; low:回溯能达最小dfn[cite: 2]
int scc[N],siz[N],cnt; // scc:节点所属SCC编号; siz:SCC大小[cite: 2]
bool in_stk[N];
vector<int> g[N];
void tarjan(int u){
  dfn[u]=low[u]=++tot;
  stk[++top]=u;in_stk[u]=1;
  for(int v:g[u]){
    if(!dfn[v]){
      tarjan(v);
      low[u]=min(low[u],low[v]);
    }else if(in_stk[v])low[u]=min(low[u],dfn[v]); // 在栈中则是后向边[cite: 2]
  }
  if(dfn[u]==low[u]){ // 找到SCC根节点[cite: 2]
    cnt++;int y;
    do{
      y=stk[top--];in_stk[y]=0;
      scc[y]=cnt;siz[cnt]++;
    }while(y!=u);
  }
}

