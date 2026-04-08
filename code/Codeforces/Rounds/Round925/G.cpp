#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=4e6+10;
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
int C(int n,int m) {
    if(n<0 || m<0 || n<m ) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}


void solve(){
    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;

    if(c1+c2==0){
        if(c3>0 && c4>0){
            cout<<0<<'\n';
        }
        else cout<<1<<'\n';
        return;
    }
    if(abs(c1-c2)>1){
        cout<<0<<'\n';
        return;
    }

    int res;
    if(c1==c2){
        int y=c1;
        res=(C(c3+y-1,y-1)*C(c4+y,y)%mod+C(c3+y,y)*C(c4+y-1,y-1)%mod)%mod;
    }
    else{
        int y=max(c1,c2);
        res=C(c3+y-1,y-1)*C(c4+y-1,y-1)%mod;
    }
    cout<<res<<'\n';

    
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    init();
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

