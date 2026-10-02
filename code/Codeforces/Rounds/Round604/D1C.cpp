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
}
int inv(int x){return qp(x,mod-2);}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        p[i]=p[i]*inv(100)%mod;
    }
    vector<int> S(n+2,1),invS(n+2,1),prefS(n+2,0);
    prefS[0]=1;
    for(int i=1;i<=n;i++){
        S[i]=(S[i-1]*p[i])%mod;
        invS[i]=inv(S[i]);
        prefS[i]=(prefS[i-1]+S[i])%mod;
    }
    auto get=[&](int l,int r){
        if(l==0) return prefS[r];
        return (prefS[r]-prefS[l-1]+mod)%mod;
    };
    auto E=[&](int L,int R){
        int num=get(L-1,R-2);
        return (num*invS[R-1])%mod;
    };
    set<int> chk;
    chk.insert(1);
    chk.insert(n+1);
    int ans=E(1,n+1);
    for(int i=0;i<q;i++){
        int u;
        cin>>u;
        if(chk.count(u)){
            auto it=chk.find(u);
            int L=*prev(it),R=*next(it);
            ans=(ans-E(L,u)+mod)%mod;
            ans=(ans-E(u,R)+mod)%mod;
            ans=(ans+E(L,R))%mod;
            chk.erase(it);
        }else{
            auto it=chk.upper_bound(u);
            int R=*it,L=*prev(it);
            ans=(ans-E(L,R)+mod)%mod;
            ans=(ans+E(L,u))%mod;
            ans=(ans+E(u,R))%mod;
            chk.insert(u);
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    solve();
    //system("pause");
    return 0;
}