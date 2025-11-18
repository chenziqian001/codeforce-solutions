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
        if(n&1) res=mul(m,res);
        m=mul(m,m);
        n>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> f0(16,vector<int>(1));
    f0[0][0]=1;


    for(int i=0;i<n;i++){
        int l,r,y;
        cin>>l>>r>>y;
        vector<vector<int>> m(16,vector<int>(16));
        for(int j=0;j<=y;j++){
            for(int k=max(0LL,j-1);k<=min(y,j+1LL);k++){
                m[j][k]=1;
            }
        }
        int times=r-l;
        if(i==n-1) times=k-l;
        f0=qp(m,f0,times); 
    }


    cout<<f0[0][0]%mod<<'\n';
    //system("pause");
}