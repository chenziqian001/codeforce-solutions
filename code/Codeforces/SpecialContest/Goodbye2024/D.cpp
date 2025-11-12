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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    auto c=a;
    auto d=b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    int res=1;
    for(int i=0;i<n;i++) res=(res*min(c[i],d[i]))%mod;
    cout<<res<<" ";
    for(int i=0;i<q;i++){
        int o,x;
        cin>>o>>x;
        x--;
        if(o==1){
            a[x]++;
            int pos=lower_bound(c.begin(),c.end(),a[x])-c.begin()-1;          
            res=res*inv(min(c[pos],d[pos]))%mod;
            c[pos]++;
            res=res*min(c[pos],d[pos])%mod;
        }
        else{
            b[x]++;   
            int pos=lower_bound(d.begin(),d.end(),b[x])-d.begin()-1;
            res=res*inv(min(c[pos],d[pos]))%mod;
            d[pos]++;
            res=res*min(c[pos],d[pos])%mod;
        }


        cout<<res<<" ";
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
}