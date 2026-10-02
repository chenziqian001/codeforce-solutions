#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=5e5+10;
int fac[N],ifac[N];
int qp(int a, int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int inv(int x) {
    return qp(x,mod-2);
}
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}


void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),w(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i]--;
    }
    for(int i=0;i<n;i++) cin>>w[i];
    vector<int> dis(n,-2),vis(n);
    function<int(int)> dfs=[&](int node){
        if(dis[node]!=-2) return dis[node];
        if(vis[node]) return dis[node]=-1;
        vis[node]=1;
        if(a[node]<a[b[node]]) dis[node]=1;
        else if(a[node]>=a[b[node]]+w[b[node]]) dis[node]=-1;
        else{
            int d=dfs(b[node]);
            if(d==-1) dis[node]=-1;
            else dis[node]=d+1;
        }
        vis[node]=2;
        return dis[node];
    };
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i);
    }
    for(int i=0;i<n;i++){
        if(dis[i]==-1) cout<<a[i]%mod<<" ";
        else cout<<(a[i]+w[i]%mod*ifac[dis[i]]%mod)%mod<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
