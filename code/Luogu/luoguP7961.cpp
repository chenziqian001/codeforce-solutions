#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int mx=31;
vector<int> fac(mx);
vector<int> ifac(mx);

int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

void init(){
    fac[0]=1;
    for(int i=1;i<mx;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[mx-1]=qpow(fac[mx-1],mod-2);
    for(int i=mx-2;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}
signed main(){
    init();
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m+1);
    for(int i=0;i<=m;i++) cin>>a[i];
    vector<vector<vector<vector<int>>>> memo(m+1,vector<vector<vector<int>>>(n+1,vector<vector<int>>(n/2+1,vector<int>(k+1,-1))));
    function<int(int,int,int,int)> dfs=[&](int i,int left_n,int x,int left_k)->int{
        int c1=__builtin_popcount((uint32_t) x);
        if(left_n==0 || i==m+1 || left_k==0){
            return left_n==0&&c1==left_k;
        }
        int &res=memo[i][left_n][x][left_k];
        if(res!=-1) return res;
        res=0;
        for(int j=0;j<=left_n;j++){
            int bit=(x+j)&1;
            int r=dfs(i+1,left_n-j,(x+j)>>1,left_k-bit);
            res=(res+1LL*r*qpow(a[i],j)%mod*ifac[j]%mod)%mod;
        }
        return res;
    };
    int ans=0;
    for(int i=0;i<=k;i++){
        ans=(ans+1LL*dfs(0,n,0,i))%mod;
    }
    ans=(ans*fac[n])%mod;
    cout<<ans<<'\n';
    return 0;    
}