#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;



int fuck(int x,int p){
    vector<int> v;
    while(x){
        v.push_back(x%p);
        x/=p;
    }
    int res=0;
    for(int num:v){
        res=(res*p%mod+num)%mod;
    }
    return res;
}//暴力转换p进制然后反转再变成十进制
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x){
    return qp(x,mod-2);
}//求逆元

int calc(int x){
    return x*(x+1)%mod*(2*x+1)%mod*inv(6LL)%mod;
}//平方和公式
void solve(){
    int n,k;
    cin>>n>>k;
    int res=0;
    if(k>n) res=((k-n+mod)%mod*n%mod)%mod;//进制大于n了不管怎么反转都是n，不会变
    int s=sqrt(n);//根号分治
    for(int p=2;p<=min(s,k);p++){
        res=(res+fuck(n,p))%mod;
    }//小于s的部分直接暴力求
    if(s+1<=k){
        for(int x=1;x<=n/(s+1);x++){
            int l=max(s+1,(n/(x+1))+1);
            int r=min(k,n/x);
            if(l>r) continue;
            res=(res+(r-l+1)*(l+r)%mod*inv(2)%mod*n%mod)%mod;
            res=(res+(r-l+1)*x%mod)%mod;
            int temp = (calc(r) - calc(l-1) + mod) % mod;
            res = (res-temp*x%mod+mod)%mod;
        }//s-n的部分转成二进制只有两位，可以用公式快速求
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}