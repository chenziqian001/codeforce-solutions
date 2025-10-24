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

void solve(){
    int n;
    cin>>n;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+(a[i]==-1);
    
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=-1) vis[a[i]]=1;
    }
    vector<vector<int>> d(n+2,vector<int>(n+2));
    int mn1=n;
    for(int i=1;i<=n;i++){
        int mn2=n;
        for(int j=n;j>=i;j--){
            int x=b[j]-b[i-1];
            int y=min(mn1,mn2);
            d[x][0]++;
            d[x][y]--;

            if(a[j]!=-1) mn2=min(mn2,a[j]);
        }
        if(a[i]!=-1) mn1=min(mn1,a[i]);
    }
    for(int i=0;i<=b[n];i++){
        for(int j=1;j<=n;j++){
            d[i][j]+=d[i][j-1];
        }
    }


    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(!vis[i]);
        for(int j=cnt;j<=b[n];j++){
            ans=(ans+C(j,cnt)*fac[cnt]%mod*fac[b[n]-cnt]%mod*d[j][i]%mod)%mod;
        }
    }
    
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
