#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[N],d[N]; // p:父节点; d:当前节点到父节点的权值(距离/关系)

void init(int n){
  iota(p+1,p+n+1,1);
  memset(d,0,sizeof d);
}

int find(int x){
  if(p[x]==x)return x;
  int root=find(p[x]);
  d[x]+=d[p[x]]; // 路径压缩时,累加路径上的权值
  return p[x]=root;
}

// 合并x,y,且已知y相对于x的权值为v (val[y]-val[x]=v)
void unite(int x,int y,int v){
  int rx=find(x),ry=find(y);
  if(rx!=ry){
    p[ry]=rx;
    d[ry]=d[x]+v-d[y]; // 核心公式:更新根节点间的权值关系
  }
}