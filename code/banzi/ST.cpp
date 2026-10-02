#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int st[N][21],lg[N];
// st[i][j] 表示从 i 开始长度为 2^j 的区间最值
// lg[i] 预处理 log2 的向下取整值，加速查询

void init(int n,vector<int>& a){
  for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1; // 预处理 log 数组
  for(int i=1;i<=n;i++)st[i][0]=a[i-1]; // 长度为 1 的区间即原数组
  for(int j=1;j<=20;j++) // 20 足够覆盖 1e6 数据量
    for(int i=1;i+(1<<j)-1<=n;i++)
      st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]); // 区间倍增合并
}

int qry(int l,int r){
  int k=lg[r-l+1]; // 找到覆盖长度的最大 2 的幂次
  return max(st[l][k],st[r-(1<<k)+1][k]); // O(1) 覆盖查询区间
}