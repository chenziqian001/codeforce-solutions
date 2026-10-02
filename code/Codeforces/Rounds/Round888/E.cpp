#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> c(n+1);
    
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        c[x]=0;
    }
    vector<vector<int>> t(n+1);
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            t[i].push_back(x);
        }
    }

    vector<int> vis(n+1);

    function<void(int)> dfs=[&](int node){
        int cur=0;
        for(int next:t[node]){
            if(!vis[next]) dfs(next);
            cur+=c[next];
        }
        vis[node]=1;
        if(t[node].size()) c[node]=min(c[node],cur);
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }


    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    cout<<'\n';




    



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

