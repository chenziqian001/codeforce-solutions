#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int tr[N][26],cnt[N],fail[N],idx;

void ins(string s){
  int p=0;
  for(char c:s){
    int v=c-'a';
    if(!tr[p][v])tr[p][v]=++idx;
    p=tr[p][v];
  }
  cnt[p]++;
}

void build(){
  queue<int> q;
  for(int i=0;i<26;i++)if(tr[0][i])q.push(tr[0][i]);
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<26;i++){
      if(tr[u][i]){
        fail[tr[u][i]]=tr[fail[u]][i]; // 儿子节点的fail指向父亲fail对应的儿子
        q.push(tr[u][i]);
      }else{
        tr[u][i]=tr[fail[u]][i]; // 关键优化：将不存在的路径指向fail路径，形成Trie图
      }
    }
  }
}

int qry(string t){
  int p=0,res=0;
  for(char c:t){
    p=tr[p][c-'a'];
    // 沿fail指针向上跳，统计所有以当前字符结尾的模式串
    for(int j=p;j&&~cnt[j];j=fail[j]){
      res+=cnt[j];
      cnt[j]=-1; // 标记-1防止在同一次查询中重复统计同一个模式串
    }
  }
  return res;
}