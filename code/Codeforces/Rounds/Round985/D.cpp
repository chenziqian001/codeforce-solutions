#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    vector<tuple<int,int,int>> res;

    for(int i=0;i<n;i++){
        while(g[i].size()>=2){
            int u=*g[i].begin();
            g[i].erase(g[i].begin());
            int v=*g[i].begin();
            g[i].erase(g[i].begin());
            g[u].erase(i),g[v].erase(i);
            res.emplace_back(i,u,v);
            if(g[u].find(v)!=g[u].end()){
                g[u].erase(v);
                g[v].erase(u);
            }
            else{
                g[u].insert(v);
                g[v].insert(u);
            }
        }
    }
    vector<int> one;
    vector<pair<int,int>> two;
    for(int i=0;i<n;i++){
        if(g[i].size()==0) one.push_back(i);
        else{
            if(*g[i].begin()>i){
                two.emplace_back(i,*g[i].begin());
            }
        }
    }

    if(!two.empty()){
        auto [x,y]=two.back();
        two.pop_back();
        for(int z:one){
            res.emplace_back(z,x,y);
            y=z;
        }
        for(auto [f,k]:two){
            res.emplace_back(y,f,k);
        }
    }
    cout<<res.size()<<'\n';
    for(auto [x,y,z]:res){
        cout<<x+1<<" "<<y+1<<" "<<z+1<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}