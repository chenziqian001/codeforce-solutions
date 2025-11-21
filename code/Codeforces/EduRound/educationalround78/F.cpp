#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
int fac[N];int ifac[N];
vector<vector<int>> stirling(N,vector<int>(N,0));//stirling[i][j]表示把i个不同元素分成j个非空集合的方法数
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
void get_stirling(){
    stirling[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            stirling[i][j]=(stirling[i-1][j-1]+j*stirling[i-1][j]%mod)%mod;
        }
    }
}//预处理斯特林数





signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    get_stirling();
    int n,m,k;
    cin>>n>>m>>k;

    int pb=inv(m);//概率
    int pp=1;//概率的幂
    int faling=1;//下降幂
    int res=0;

    int upto=min(n,k);
    for(int i=0;i<=upto;i++){
        if(i){
            pp=pp*pb%mod;
            faling=faling*(n-i+1+mod)%mod;
        }
        res=(res+stirling[k][i]*pp%mod*faling%mod)%mod;
    }


    cout<<res<<'\n';

    //system("pause");
}
