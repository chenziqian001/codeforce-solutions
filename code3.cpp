#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+1;
long long a[N+1];
void dfs(int node,int parent,long long mini,long long maxi,vector<long long>& res,vector<vector<long long>>& graph){
    res[node]=max(a[node],a[node]-mini);
    mini=min(a[node],a[node]-maxi);
    for(int next:graph[node]){
        if(next==parent) continue;
        dfs(next,node,mini,res[node],res,graph);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<long long>> graph(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<long long> res(n+1);
    
    dfs(1,-1,0,0,res,graph);
    
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
        
    }
    cout<<'\n';
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
    
}


