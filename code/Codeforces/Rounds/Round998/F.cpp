#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+10;
vector<int> fac(20);
vector<vector<int>> dp(N,vector<int>(33));
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
int C(int n,int m){
    int res=1;
    for(int i=1,j=n;i<=m;i++,j--){
        res=res*j%mod*inv(i)%mod;
    }
    return res;
}

void solve(){
    int k,n;
    cin>>k>>n;
    vector<int> c(35);
    for(int i=0;i<35;i++){
        c[i]=C(n+1,i+1);
    }
    for(int i=1;i<=k;i++){
        if(i==1){
            cout<<n<<" ";
            continue;
        }
        int ans=0;
        for(int j=1;j<=min(n,30LL);j++){
            ans=(ans+1LL*dp[i][j]*c[j]%mod)%mod;
        }
        cout<<ans<<" ";
    }
    cout<<'\n';  
}
signed main(){
    dp[1][0]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<=30;j++){
            for(int p=2;1LL*p*i<N;p++){
                dp[i*p][j+1]+=dp[i][j];
                dp[i*p][j+1]%=mod;
            }
        }
    }
    dp[1][1]=1;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


