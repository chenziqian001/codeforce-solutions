#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> res(n);
    int pin=1;
    res[0]=pin;
    function<void(int,int)> dfs=[&](int node,int fa){
        for(int next:t[node]){
            if(next==fa) continue;
            res[next]=pin+1;
            while(res[next]!=res[node]+1 && (res[next]%2 != res[node]%2 || res[next]-res[node]==2)){
                res[next]++;
            }
            pin=res[next];
            dfs(next,node);
        }
    };
    dfs(0,-1);
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}