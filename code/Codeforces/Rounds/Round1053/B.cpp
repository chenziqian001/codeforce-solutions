#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

int inv(int x){
    return qpow(x,mod-2);
}
int fac[N];
int ifac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-1;i>=1;i--){
        ifac[i-1]=ifac[i]*i%mod;
    }
}
int C(int m,int n){
    if(m>n) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> avalible(n);
    for(int i=0;i<n/2;i++) avalible[i]=2;
    if(n&1) avalible[n/2]=1;

    int av=0;
    int res=1;
    for(int i=n-1;i>=0;i--){
        av+=avalible[i];
        if(a[i]>av){
            cout<<0<<'\n';
            return;
        }
        res=(res*C(a[i],av)%mod)%mod;
        av-=a[i];
    }
    if(av>0){
        cout<<0<<'\n';
        return;
    }
    cout<<res<<'\n';

}
signed main(){
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}