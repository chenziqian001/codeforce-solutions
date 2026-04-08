#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> tp(n,-1);

    int res=0;
    for(int i=0;i<n;i++){
        if(tp[i]!=-1) continue;
        queue<int> q;
        q.push(i);
        int c0=0;
        int c1=0;


        tp[i]=0;
        bool ok=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(tp[u]==0){
                c0++;
            }
            else{
                c1++;
            }
            for(int nx:g[u]){
                if(tp[nx]==-1){
                    tp[nx]=tp[u]^1;
                    q.push(nx);
                }
                else{
                    if(tp[nx]!=tp[u]^1){
                        ok=false;
                    }
                }
            }
        }
        if(ok){
            res+=max(c0,c1);
        }
    }

    cout<<res<<'\n';
    




}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}