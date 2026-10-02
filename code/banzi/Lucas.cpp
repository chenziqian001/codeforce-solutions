#include<bits/stdc++.h>
using namespace std;
#define int long long

// 应用场景注释：
// 1. 计算 C(n, m) % p，其中 p 是质数且 p 较小 (通常 p < 10^6)。
// 2. n 和 m 的范围极大 (可达 10^18)。
// 3. 如果 p 不是质数，需使用扩展卢卡斯定理 (ExLucas)，此处为基础版。

int qpow(int a,int b,int p){
    int res=1;a%=p;
    while(b){
        if(b&1)res=res*a%p;
        a=a*a%p;b>>=1;
    }
    return res;
}

// 基础组合数 C(n, m) % p，利用逆元计算
int C(int n,int m,int p){
    if(m<0||m>n)return 0;
    if(m==0||m==n)return 1;
    if(m>n/2)m=n-m;
    int up=1,down=1;
    for(int i=0;i<m;i++){
        up=up*(n-i)%p;
        down=down*(i+1)%p;
    }
    return up*qpow(down,p-2,p)%p;
}

// Lucas 定理递归实现
int lucas(int n,int m,int p){
    if(m==0)return 1;
    return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
