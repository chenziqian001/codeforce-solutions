#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
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


void solve(){
    int n;
    cin>>n;

    map<int,int,greater<int>> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }

    vector<int> c;
    for(auto i:mp){
        c.push_back(i.second);
    }
    int k=n/2;

    auto get=[&](int p){
        if(p==0) return 0LL;
        if(p<k) return p-1;
        return k;
    };

    vector<int> dp(n+1,0);
    dp[0]=1;
    int s=0;


    for(int x:c){
        vector<int> ndp(n+1);
        for(int p=0;p<=k;p++){
            if(!dp[p]) continue;
            int j=get(p)-(s-p);
            if(j>=x){
                ndp[p]=(ndp[p]+dp[p]*C(j,x)%mod)%mod;
            }


            if(p<k && j>=x-1) ndp[p+1]=(ndp[p+1]+dp[p]*C(j,x-1)%mod)%mod;
        }
        dp=ndp;
        s+=x;
    }
    cout<<dp[k]<<'\n';
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