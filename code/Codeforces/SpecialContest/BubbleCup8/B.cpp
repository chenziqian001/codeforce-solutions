#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

struct E{int u,v,tp;};
const int mod=1e9+7;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}



void solve(){
    int n;
    cin>>n;
    vector<E> e(n);
    vector<vector<int>> t(n+1);
    for(int i=1;i<n;i++){
        cin>>e[i].u>>e[i].v>>e[i].tp;
        t[e[i].u].push_back(e[i].v);
        t[e[i].v].push_back(e[i].u);
    }
    vector<int> U(n+1);
    vector<int> D(n+1);
    vector<vector<int>> fa(n+1,vector<int>(21));
    vector<int> dep(n+1);
    function<void(int,int)> dfs=[&](int node,int f){
        fa[node][0]=f;
        dep[node]=dep[f]+1;
        for(int i=1;i<18;i++) fa[node][i]=fa[fa[node][i-1]][i-1];
        for(int next:t[node]){
            if(next==f) continue;
            dfs(next,node);
        }
    };
    dfs(1,0);

    auto lca=[&](int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        for(int i=20;i>=0;i--){
            if((dep[u])-(1<<i)>=dep[v]){u=fa[u][i];}
        }
        if(u==v){return u;}
        for(int i=20;i>=0;i--){
            if(fa[u][i]!=fa[v][i]){
                u=fa[u][i];
                v=fa[v][i];
            }
        }
        return fa[u][0];
    };
    int k;cin>>k;
    int cur=1;
    for(int i=0;i<k;i++){
        int nx;
        cin>>nx;
        int lc=lca(cur,nx);
        U[cur]++;U[lc]--;D[lc]--;D[nx]++;
        cur=nx;
    }
    function<void(int,int)> calc=[&](int node,int fa){
        for(int next:t[node]){
            if(next==fa) continue;
            calc(next,node);
            U[node]+=U[next];
            D[node]+=D[next];
        }
    };
    calc(1,0);

    int res=0;
    for(int i=1;i<n;i++){
        int u=e[i].u,v=e[i].v;
        if(e[i].tp==1){
            if(dep[u]>dep[v]){
                res=(res+qp(2,D[u])-1+mod)%mod;
            }
            else{
                res=(res+qp(2,U[v])-1+mod)%mod;
            }
        }
    }
    cout<<res<<'\n';  
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