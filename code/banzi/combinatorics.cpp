#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
int fac[N];int ifac[N];
//插板法，每人至少分到1,C(n-1,m-1),允许为空:C(n+m-1,m-1);
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
vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b){
    int ra=a.size();
    int ca=a[0].size();
    int cb=b[0].size();
    vector<vector<int>> res(ra,vector<int>(cb));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            if(a[i][j]==0) continue;
            for(int k=0;k<cb;k++){
                res[i][k]=(res[i][k]+a[i][j]*b[j][k]%mod+mod)%mod;
            }
        }
    }
    return res;
}
vector<vector<int>> qp(vector<vector<int>> m,vector<vector<int>> f0,int n){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1) res=mul(m,f0);
        m=mul(m,m);
        n>>=1;
    }
    return res;
}

// 求ax+by=gcd(a,b)的一组解。返回d=gcd(a,b)
// 1. 求逆元: ax≡1(mod m) -> exgcd(a,m,x,y), 若d==1, 则inv=(x%m+m)%m
// 2. 线性同余: ax≡b(mod m) -> ax+my=b, 若b%d!=0无解, 否则x*=(b/d), 最小正整数解x=(x%(m/d)+(m/d))%(m/d)
int exgcd(int a,int b,int &x,int &y){
  if(!b){x=1,y=0;return a;}
  int d=exgcd(b,a%b,y,x);
  y-=a/b*x;
  return d;
}
void solve(){   }
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
