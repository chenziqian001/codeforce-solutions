#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=2e18;



int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
struct e{
    int v,w;
};


void solve(){
    int n,m,t;
    cin>>n>>m>>t;
    string s;
    cin>>s;
    s=" "+s;
    vector<vector<e>> g(n+1);
    vector<int> indeg(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        indeg[v]++;
    }


    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }


    vector<int> od;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        od.push_back(u);
        for(const auto &p:g[u]){
            int v=p.v;
            if(--indeg[v]==0){
                q.push(v);
            }
        }
    }

    vector<int> dis(n+1,inf),way(n+1);
    vector<int> dp(n+1,inf);
    dp[t]=0;
    dis[t]=0;
    way[t]=1;
    for(int i=n-1;i>=0;i--){
        int u=od[i];
        if(u==t) continue;
        for(const auto &p:g[u]){
            dis[u]=min(dis[u],p.w+dis[p.v]);
        }
        int as=0;
        int ss=0;
        for(const auto &p:g[u]){
            int v=p.v,w=p.w;
            int c=(w%mod+dp[v])%mod;
            as=(as+c)%mod;

            if(dis[u]==w+dis[v]){
                way[u]=(way[u]+way[v])%mod;
                ss=(ss+way[v]*c%mod)%mod;
            }


            
        }
        if(s[u]=='1'){
            dp[u]=ss*qp(way[u],mod-2)%mod;
        }
        else{
            int deg=g[u].size();
            dp[u]=as*qp(deg,mod-2)%mod;
        }
    }


    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}