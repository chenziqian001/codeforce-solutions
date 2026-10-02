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
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    int cur=0;
    for(int i=0;i<n;i++){
        cur=(cur+1)*100%mod*inv(p[i])%mod;
    }
    cout<<cur<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}