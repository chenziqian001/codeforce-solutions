#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> s(5010);
    s[0]=1;

    for(int i=1;i<=k;i++){
        for(int j=i;j>=1;j--) s[j]=(s[j]*j+s[j-1])%mod;
        s[0]=0;
    }
    int c=1;
    int res=0;
    for(int j=1;j<=k && j<=n;j++){
        c=c*(n-j+1)%mod;
        res=(res+s[j]*c%mod*qp(2,n-j))%mod;
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    

    //system("pause");
    return 0;
}