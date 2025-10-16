#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n;

int qp(int a,int t){
    int res=1;
    while(t){
        if(t&1) res=(res*a)%mod;
        a=(a*a)%mod;
        t>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

int pk(int cnt0,int pre0){
    return 2*((cnt0-pre0)*(cnt0-pre0)%mod) % mod * inv(n) % mod * inv(n-1) % mod;
}




void solve(){
    cin>>n;
    vector<int> a(n);
    int cnt0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt0+=(a[i]==0);
    }
    vector<int> dp(cnt0+1);
    dp[cnt0]=0;
    int k=0;
    for(int i=0;i<cnt0;i++){
        if(a[i]==0) k++;
    }
    for(int i=cnt0-1;i>=k;i--){
        dp[i]=(dp[i+1]+inv(pk(cnt0,i)))%mod;
    }
    cout<<dp[k]<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}