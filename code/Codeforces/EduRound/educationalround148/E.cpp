#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e7+5;
int fac[N];int ifac[N];
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x) {return qp(x,mod-2);}//逆元
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;    
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}//初始化阶乘
int C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}//组合数

vector<int> p(vector<int> a){
    vector<int> res(1,0);
    for(int x:a){
        res.push_back((res.back()+x)%mod);
    }
    return res;
}




signed main(){

    int n,a1,x,y,m,k;
    cin>>n>>a1>>x>>y>>m>>k;
    

}