#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> deg(n);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        t[u].push_back(v);
        t[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans=0;
    for(int u=0;u<n;u++){
        for(int v:t[u]){
            if(u<v && deg[u]%2!=0 && deg[v]%2!=0){
                ans++;
            }
        }
    }

    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(deg[i]%2==0 && !vis[i]){
            int k=0;
            queue<int> q;
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:t[u]){
                    if(deg[v]%2!=0){
                        k++;
                    }
                    else if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
            ans+=k*(k-1)/2;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}