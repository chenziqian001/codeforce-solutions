#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ch(n);
    vector<int> seq;
    auto dfs=[&](auto& self,int u,int p)->void{
        for(int v:adj[u]){
            if(v!=p){
                ch[u].push_back(v);
                self(self,v,u);
            }
        }
        seq.push_back(u);
    };
    dfs(dfs,0,-1);
    vector<vector<int>> F(n,vector<int>(n)),C(n,vector<int>(n));
    for(int i=0;i<n;i++){
        int u=seq[i];
        for(int j=0;j<n;j++){
            int v=seq[j];
            int r=0,c=0,sum=0;
            for(int x:ch[u]){
                r=(r+F[x][v])%mod;
                sum=(sum+C[x][v])%mod;
            }
            for(int y:ch[v]){
                c=(c+F[u][y])%mod;
            }
            C[u][v]=c;
            int val=(s[u]==s[v])?(1+sum)%mod:0;
            F[u][v]=(val+r+c-sum+mod)%mod;
        }
    }
    for(int i=0;i<n;i++){
        cout<<F[i][i]<<" \n"[i==n-1];
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}