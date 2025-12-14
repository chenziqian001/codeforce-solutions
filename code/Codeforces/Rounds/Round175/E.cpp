#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=1100;
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


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n,k;
    cin>>n>>k;
    vector<vector<vector<vector<int>>>> f(n+1,vector<vector<vector<int>>>(n+1,vector<vector<int>>(2,vector<int>(2))));
    f[1][0][0][0]=f[1][1][0][1]=1;
    for(int i=2;i<n;i++){
        f[i][0][0][0]=1;
        for(int j=1;j<=i;j++){
            //强制完美
            f[i][j][0][0]=(f[i][j][0][0]+f[i-1][j-1][0][0])%mod;
            f[i][j][1][0]=(f[i][j][1][0]+f[i-1][j-1][0][1])%mod;
            f[i][j][0][1]=(f[i][j][0][1]+f[i-1][j-1][0][0]+f[i-1][j-1][1][0])%mod;
            f[i][j][1][1]=(f[i][j][1][1]+f[i-1][j-1][0][1]+f[i-1][j-1][1][1])%mod;
            //不管
            f[i][j][0][0]=(f[i][j][0][0]+f[i-1][j][0][0]+f[i-1][j][1][0])%mod;
            f[i][j][1][0]=(f[i][j][1][0]+f[i-1][j][0][1]+f[i-1][j][1][1])%mod;
        }
    }
    f[n][0][0][0]=1;
    for (int j=1;j<=n;j++){
        f[n][j][0][0]=(f[n-1][j-1][0][0]+f[n-1][j][0][0]+f[n-1][j][1][0])%mod;
        f[n][j][1][0]=(f[n-1][j-1][0][1]+f[n-1][j][0][1]+f[n-1][j][1][1])%mod;
    }



    vector<int> F(n+1);
    for(int i=0;i<=n;i++){
        F[i]=(f[n][i][0][0]+f[n][i][1][0])*fac[n-i]%mod;
    }
    int res=0;


    for(int i=k;i<=n;i++){
        int val=C(i,k)*F[i]%mod;
        if((i-k)&1){
            res=(res-val+mod)%mod;
        }
        else res=(res+val)%mod;
    }


    cout<<res<<'\n';
    //system("pause");
}