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



void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++) b[i]=upper_bound(a.begin()+1,a.begin()+i,a[i]/2)-a.begin()-1;

    if(b[n]!=n-1){
        cout<<0<<'\n';
        return;
    }
    vector<int> A(n+1,1),iA(n+1,1);
    for(int i=1;i<=n;i++) A[i]=A[i-1]*i%mod;
    iA[n]=qp(A[n],mod-2);
    for(int i=n-1;i>=0;i--) iA[i]=iA[i+1]*(i+1)%mod;

    auto P=[&](int n,int m)->int{
        if(n<0||m<0||n<m) return 0;
        return A[n]*iA[n-m]%mod;
    };

    vector<int> dp(n+1);

    for(int i=1;i<=n;i++){
        dp[i]=P(n-1,b[i]);
        for(int j=1;j<=b[i];j++){
            dp[i]=(dp[i]+dp[j]*P(n-b[j]-2,b[i]-b[j]-1)%mod)%mod;
        }
    }
    cout<<dp[n]<<'\n';
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