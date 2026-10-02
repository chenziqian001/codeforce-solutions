#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1); 

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> node;
    for(int i=1;i<=n;i++){
        if(deg[i]%2==1){
            node.push_back(i);
        }
    }
    cout<<(node.size()+1)/2<<'\n';
    for(int i=0;i+1<node.size();i+=2){
        cout<<node[i]<<" "<<node[i+1]<<'\n';
    }
    if(node.size()%2==1){
        cout<<node.back()<<" "<<node.back()<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}