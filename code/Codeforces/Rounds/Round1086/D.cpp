#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<n;j++){
            c[i]+=(s[i][j]=='1');
        }
    }

    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),[&](int x,int y){return c[x]>c[y];});
    vector<pair<int,int>> e;
    vector<int> cov(n);
    for(int i=0;i<n;i++){
        fill(cov.begin(),cov.end(),0);
        for(int j:p){
            if(i!=j && s[i][j]=='1' && !cov[j]){
                e.push_back({i,j});
                for(int k=0;k<n;k++) if(s[j][k]=='1') cov[k]=1;
            }
        }
        if(e.size()>=n){
            break;
        }
    }

    if((int)e.size()!=n-1){
        cout<<"NO"<<'\n';
        return;
    }

    vector<vector<int>> ud(n),d(n);
    for(auto p:e){
        ud[p.first].push_back(p.second);
        ud[p.second].push_back(p.first);
        d[p.first].push_back(p.second);
    }
    vector<int> vis(n);
    int cnt=0;
    auto dfs=[&](auto& self,int u)->void{
        vis[u]=1;
        cnt++;
        for(int v:ud[u]) if(!vis[v]) self(self,v);
    };
    dfs(dfs,0);
    if(cnt!=n){
        cout<<"NO"<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        fill(vis.begin(),vis.end(),0);
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int v:d[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        for(int j=0;j<n;j++){
            if(vis[j]!=(s[i][j]=='1')){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES"<<'\n';
    for(auto p:e){
        cout<<p.first+1<<" "<<p.second+1<<'\n';
    }


    
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
