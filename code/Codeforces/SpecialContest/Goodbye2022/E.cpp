#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=3e5+10;
int fac[N],ifac[N];
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> prob(n+1);
    vector<int> sum(n+1);
    for(int i=0;i<k;i++){
        int pos;
        cin>>pos;
        if(pos<1 || pos>n) continue; // 防护：输入异常时跳过（或改为报错）
        sum[pos]++;
        prob[pos]=1;
    }
    vector<vector<int>> t(n+1);
   
    vector<int> u(n-1);
    vector<int> v(n-1);
    for(int i=0;i<n-1;i++){
        cin>>u[i]>>v[i];
        t[u[i]].push_back(v[i]);
        t[v[i]].push_back(u[i]);
    }
    vector<int> p(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        p[node]=fa;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            sum[node]+=sum[next];
        }
    };
    dfs(1,0);
    int res=0;
    int inv2 = inv(2);
    if(k < 2){
        cout << 0 << '\n';
        return;
    }
    for(int i=0;i<n-1;i++){
        if(v[i]==p[u[i]]) swap(v[i],u[i]);
        int siz=sum[v[i]],other=k-sum[v[i]];
        int pu=prob[u[i]],pv=prob[v[i]];
        int ss=pu*pv%mod,gg=(1-pu+mod)%mod*((1-pv+mod)%mod)%mod,gs=pu*((1-pv+mod)%mod)%mod,sg=(1-pu+mod)%mod*pv%mod;
        int keep=(ss+gg+(sg+gs)*inv2%mod)%mod;
        res=(res+siz*other%mod*keep%mod)%mod;
        res=(res+(siz+1)*(other-1)%mod*gs%mod*inv2%mod)%mod;
        res=(res+(siz-1)*(other+1)%mod*sg%mod*inv2%mod)%mod;
        prob[u[i]] = prob[v[i]] = ( (prob[u[i]] + prob[v[i]]) % mod ) * inv2 % mod;
    }
    int denom = ( (k%mod) * ((k-1)%mod) ) % mod;
    denom = denom * inv2 % mod; 
    int inv_den = inv( (int)denom );
    cout << res * 1LL * inv_den % mod << '\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}