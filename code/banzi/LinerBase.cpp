#include<bits/stdc++.h>
using namespace std;
#define int long long
struct LB{
    int d[61];
    LB(){memset(d,0,sizeof(d));}
    // 插入
    void ins(int x){
        for(int i=60;i>=0;i--)if(x&(1LL<<i)){
            if(!d[i]){d[i]=x;return;}
            x^=d[i];
        }
    }
    // 查询最大异或值
    int query_max(){
        int res=0;
        for(int i=60;i>=0;i--)res=max(res,res^d[i]);
        return res;
    }
    // 查询是否存在（能被当前基异或出来）
    bool check(int x){
        for(int i=60;i>=0;i--)if(x&(1LL<<i)){
            if(!d[i])return 0;
            x^=d[i];
        }
        return 1;
    }
};
// 合并两个线性基：将一个基的所有元素插入另一个
LB merge(LB a,LB b){
    LB res=a;
    for(int i=60;i>=0;i--)if(b.d[i])res.ins(b.d[i]);
    return res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,x;cin>>n;
    LB base;
    while(n--)cin>>x,base.ins(x);
    cout<<base.query_max()<<"\n";
    return 0;
}