#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

/*void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    long long res=-1e18;
    for(int i=0;i<n;i++){
        long long val=abs(pre[i]+a[i])+pre[n]-pre[i+1];
        res=max(res,val);
    }


    cout<<res<<'\n';
}*/

long long qpow(long long a,long long n){
    long long res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long mn=0,sum=0,cnt=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        mn=min(mn,sum);
    }
    if(mn==0){
        cout<<qpow(2,n)<<'\n';
        return;
    }
    sum=0;
    long long res=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==mn){
            res=(res+qpow(2,cnt+n-i-1)%mod)%mod;
        }
        if(sum>=0) cnt++;
    }
    cout<<res<<'\n';
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}