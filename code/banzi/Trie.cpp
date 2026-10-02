#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; // 根据题目总字符数设定
int tr[N][26],cnt[N],idx; // tr:字典树节点; cnt:记录以该节点结尾的串个数; idx:动态分配节点编号

void ins(string s){
  int p=0;
  for(char c:s){
    int v=c-'a';
    if(!tr[p][v])tr[p][v]=++idx; // 不存在该字符路径则新建节点
    p=tr[p][v];
  }
  cnt[p]++; // 在单词末尾标记次数
}

int qry(string s){
  int p=0;
  for(char c:s){
    int v=c-'a';
    if(!tr[p][v])return 0; // 路径断了，说明该串没出现过
    p=tr[p][v];
  }
  return cnt[p]; // 返回该单词完整出现的次数
}