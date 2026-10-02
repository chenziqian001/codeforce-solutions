#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int k;
    cin>>k;
    int n=(1LL<<(k+1));

    vector<int> g(n+1), pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>g[i];
        pre[i]=pre[i-1]^g[i];
    }

    vector<vector<int>> gp(1<<k);
    for(int i=0;i<=n;i++){
        gp[pre[i]&((1<<k)-1)].push_back(i);
    }
    
    vector<vector<pair<int,int>>> s(1<<k);
    for(int b=0;b<(1<<k);b++){
        for(int x=0;x<gp[b].size();x++){
            for(int y=x+1;y<gp[b].size();y++){
                int i=gp[b][x], j=gp[b][y];
                int v=(pre[i]^pre[j])>>k;
                for(auto& p:s[v]){
                    int u=p.first, w=p.second;
                    if(u!=i && u!=j && w!=i && w!=j){
                        vector<int> ans={u,w,i,j};
                        sort(ans.begin(),ans.end());
                        cout<<ans[0]+1<<" "<<ans[1]<<" "<<ans[2]+1<<" "<<ans[3]<<'\n';
                        return;
                    }else if(w==i){
                        cout<<u+1<<" "<<w<<" "<<i+1<<" "<<j<<'\n';
                        return;
                    }else if(u==j){
                        cout<<i+1<<" "<<j<<" "<<u+1<<" "<<w<<'\n';
                        return;
                    }
                }
                s[v].push_back({i,j});
            }
        }
    }
    cout<<"-1\n";
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