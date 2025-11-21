#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=5010;
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

vector<vector<int>> stirling(N,vector<int>(N,0));//stirling[i][j]表示把i个不同元素分成j个非空集合的方法数
void get_stirling(){
    stirling[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            stirling[i][j]=(stirling[i-1][j-1]+j*stirling[i-1][j]%mod)%mod;
        }
    }
}//斯特林数递推式S[i][j]=S[i-1][j-1]+j*S[i-1][j]

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    vector<int> super(1<<20);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        super[x]++;
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<(1<<20);j++){
            if(((j>>i)&1)==0){
                super[j]=(super[j]+super[j|(1<<i)])%mod;
            }
        }
    }

    int res=0;
    for(int x=0;x<(1<<20);x++){
        res=(res+(__builtin_popcount(x)%2==0?1:-1)*qp(2,(super[x]))+mod)%mod;
    }


    cout<<res<<'\n';
    //system("pause");
}