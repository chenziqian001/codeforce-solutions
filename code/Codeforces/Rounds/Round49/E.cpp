#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;

    int mx=1<<n;
    vector<vector<int>> g(n,vector<int>(n));
    vector<vector<int>> f(mx,vector<int>(mx));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u][v]=1,g[v][u]=1;
        int st=(1<<u)|(1<<v);
        f[st][st]=2;
    }


    for(int p=1;p<mx;p++){
        for(int q=p;q;q=(q-1)&p){
            f[p][q]/=__builtin_popcount(q);
            for(int i=0;i<n;i++){
                if(!(p&(1<<i))) continue;
                int t=q&((mx-1)^(1<<i));
                for(int j=0;j<n;j++){
                    if(p&(1<<j) || !g[i][j]) continue;
                    f[p|(1<<j)][t|(1<<j)]+=f[p][q];
                }
            }
        }
    }


    int res=0;
    for(int i=0;i<mx;i++){
        int kk=__builtin_popcount(i);
        if(kk==k){
            res+=f[mx-1][i];
        }
    }

    cout<<res<<'\n';
    //system("pause");
    return 0;

}