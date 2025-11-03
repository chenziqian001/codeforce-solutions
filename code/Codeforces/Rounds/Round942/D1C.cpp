#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

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
    int n,k;
    cin>>n>>k;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> C(n+1);
    C[0]=1;
    int u=k,v=1;
    for(int i=1;i<=n;i++){
        C[i]=C[i-1]*u%mod*inv(v)%mod;
        u++,v++;
    }

    for(int i=1;i<=n;i++){
        int d=1;
        for(int u=i+(i&-i);u<=n;u+=(u&-u)){
            b[u]=(b[u]-b[i]*C[d]%mod+mod)%mod;
            d++;
        }
    
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}