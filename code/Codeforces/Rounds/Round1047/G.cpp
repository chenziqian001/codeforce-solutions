#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> rg(n);
    vector<int> next(n);
    vector<int> dp1(n,1);
    vector<int> dp2(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        next[u]++;
        rg[v].push_back(u);
    }
   

    while(q--){
        int x,u;
        cin>>x>>u;
        u--;
        if(x==1){
            queue<pair<int,int>> q;
            if(dp1[u]) q.push({u,0});
            if(!dp2[u]){
                dp2[u]=1;
                q.push({u,1});
            }
            while(!q.empty()){
                auto [u,turn]=q.front();
                q.pop();
                if(turn){
                    for(int pre:rg[u]){
                        --next[pre];
                        if(next[pre]==0){
                            q.push({pre,0});
                        }
                    }
                }
                else{
                    if(dp1[u]==0) continue;
                    dp1[u]=0;
                    for(int pre:rg[u]){
                        if(dp2[pre]) continue;
                        dp2[pre]=1;
                        q.push({pre,1});
                    }
                }
            }
        }
        else{
            if(dp1[u]) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}