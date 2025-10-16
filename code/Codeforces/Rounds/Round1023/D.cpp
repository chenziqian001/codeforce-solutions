#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<bool> used(n+1,false),seen(n+1,false);
    vector<array<int,3>> ans;
    vector<int> p(n+1,-1);
    while(true){
        if(count(used.begin()+1,used.end(),false)==0) break;
        seen.assign(n+1,false);
        auto dfs=[&](auto self,int u,int fa)->pair<int,int>{
            pair<int,int> ret={1,u};
            p[u]=fa;
            seen[u]=true;
            for(int v:t[u]){
                if(v==fa || used[v]) continue;
                auto pi=self(self,v,u);
                pi.first++;
                if(pi>ret) ret=pi;
            }
            return ret;
        };
        for(int i=1;i<=n;i++){
            if(used[i] || seen[i]) continue;
            auto [d1,j]=dfs(dfs,i,-1);
            auto [d2,k]=dfs(dfs,j,-1);
            ans.push_back({d2,max(j,k),min(j,k)});
            while(k!=-1){
                used[k]=true;
                k=p[k];
            }
        }
    }
    sort(ans.begin(),ans.end(),greater<array<int,3>>());
    for(int i=0;i<ans.size();i++){
        int x=ans[i][0];
        int y=ans[i][1];
        int z=ans[i][2];
        cout<<x<<" "<<y<<" "<<z<<" ";
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}



