#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<vector<int>> p(n,vector<int>(20,-1));
    vector<int> rk1(n),rk2(n);
    vector<int> dep(n);
    auto dfs1=[&](auto&& self,int u)->void{
        for(auto v:t[u]){
            if(p[u][0]==v) continue;
            dep[v]=dep[u]+1;
            p[v][0]=u;
            for(int bit=1;bit<=__lg(dep[v]);bit++){
                p[v][bit]=p[p[v][bit-1]][bit-1];
            }
            self(self,v);
            int tmp=rk1[v]+1;
            if(tmp>=rk1[u]){
                rk2[u]=rk1[u];
                rk1[u]=tmp;
            }
            else if(tmp>rk2[u]) rk2[u]=tmp;

        }
    };
    dfs1(dfs1,0);
    vector<array<int,20>> dp(n);
    auto dfs2=[&](auto &&self,int u)->void{
        for(int v:t[u]){
            if(p[u][0]==v) continue;
            dp[v][0]=((rk1[v]+1==rk1[u])?rk2[u]:rk1[u])+1;
            for(int bit=1;bit<=__lg(dep[v]);bit++){
                dp[v][bit]=max(dp[v][bit-1],dp[p[v][bit-1]][bit-1]+(1<<(bit-1)));
            }
            self(self,v);
        }

    };
    dp[0][0]=rk1[0];
    dfs2(dfs2,0);


    int q;
    cin>>q;
    while(q--){
        int node,k;
        cin>>node>>k;
        node--;
        k=min(k,dep[node]);
        int res=rk1[node];
        int sum=0;
        for(int bit=19;bit>=0;bit--){
            if(k>=(1<<bit)){
                res=max(res,dp[node][bit]+sum);
                node=p[node][bit];
                k-=(1<<bit);
                sum+=(1<<bit);                
            }
        }
        cout<<res<<" ";
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}