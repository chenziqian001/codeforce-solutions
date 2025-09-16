#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=2e5+10;
#define int long long
// int fac[N];
// int ifac[N];
/*int pow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}*/
/*int c(int n,int m){
    if(n>m) return 0;
    return fac[m]*ifac[n]%mod*ifac[m-n]%mod;
}*/
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> dp(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    dp[1]=a[1];
    vector<int> A(n+1);
    A[1]=1;
    for(int i=2;i<=n;i++){
        A[i]=(A[i-1]*3-1+mod)%mod;
    }
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]*2%mod+a[i]*A[i]%mod)%mod;
    }

    cout<<dp[n]%mod<<'\n';
}



signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}