#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;

    vector<int> f(n,(1<<30)-1);
    vector<vector<array<int,2>>> adj(n);
    
    while(q--){
        int u,v,x;
        cin>>u>>v>>x;
        u--,v--;
        f[u]&=x;
        f[v]&=x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }  

    for(int i=0;i<n;i++){
        int t=0;
        for(auto p:adj[i]){
            int j=p[0];
            int x=p[1];
            t|=x&~f[j];
            if(i==j){
                t=x;
            }

        }
        f[i]=t;
        cout<<f[i]<<" ";
    }
    cout<<'\n';
    //system("pause");
}
