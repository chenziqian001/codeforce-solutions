#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=6000;
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
/*
int res=0;
int n,m,k;
int get(int x,int y,int round){
    if(round==k) return 1;
    int res=0;
    for(int i=1;i<=x-2;i++){
        for(int j=1;j<=y-2;j++){
            res=(res+(x-1-i)*(y-1-j)%mod*get(i,j,round+1)%mod)%mod;
        }
    }

    return res;
}
*/


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n,m,k;
    cin>>n>>m>>k;
    if(2*k>m-1 || 2*k>n-1){
        cout<<0<<'\n';
    }
    else{
        cout<<C(n-1,2*k)*C(m-1,2*k)%mod<<'\n';;
    }

    //system("pause");
}


