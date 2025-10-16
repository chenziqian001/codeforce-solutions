#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

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

void solve(){
    int n,l,k;
    cin>>n>>l>>k;
    vector<int> f(n,0);
    f[0]=1;
    for(int x=2;x<=l;x++){
        vector<int> cnt(n);
        for(int i=0;i<x;i++){
            cnt[i%n]=(cnt[i%n]+1)%mod;
        }
        vector<int> g(n);
        for(int i=0;i<n;i++){
            g[i]=(g[i]+cnt[i])%mod;
            for(int j=0;j<n;j++){
                int pos=(i+1+j)%n;
                g[pos]+=f[j]*cnt[i]%mod;
                g[pos]%=mod;
            }
        }
        for(int i=0;i<n;i++){
            g[i]=g[i]*inv(x)%mod;
        }
        swap(g,f);
    }


    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
    cout<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}