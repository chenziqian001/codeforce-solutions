#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int mod=998244353;
const int N=2e5+10;
vector<int> g[N],dcc[N];
int dfn[N],low[N],id;
int stk[N],top,p[N],cnt;
void tarjan(int u,int fa=-1){
    dfn[u]=low[u]=++id;
    stk[++top]=u;
    for(int v:g[u]){
        if(!dfn[v]) tarjan(v,u), low[u]=min(low[u],low[v]);
        else if(v!=fa) low[u]=min(low[u],dfn[v]); 
    }
    if(dfn[u]==low[u]){
        cnt++;
        for(int x=-1;x!=u;){
            if(top<0) break;
            x=stk[top--];
            p[x]=cnt;
            dcc[cnt].push_back(x);
        }
    }
}
int col[N];
bool check(int u,int f=0){
    if(~col[u]) return col[u]==f; col[u]=f;
    for(int v:g[u]) if(p[u]==p[v] && !check(v,f^1)) return 0;
    return 1;
}
int ans;
void solve(){
    id=top=0,ans=1;
    cnt=0;
    int n,m,v;
    cin>>n>>m>>v;
    for(int i=0;i<n;i++) dfn[i]=low[i]=p[i]=0,col[i]=-1;
    for(int i=0;i<=n;i++) g[i].clear(),dcc[i].clear();
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=cnt;i++){
        int x=-1;
        for(int u:dcc[i]){
            if(a[u]<0) continue;
            if(x<0) x=a[u];
            else if(x!=a[u]) {ans=0;break;}   
        }
        if(!ans) break;
        bool f=check(dcc[i][0]);
        if(f){
            if((x<0)) ans=ans*v%mod;
        }
        else if(x>0) ans=0;
        if(!ans) break;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}