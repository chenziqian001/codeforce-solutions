#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> t[N];
vector<pair<int,int>> ask[N];
map<int,int> fq[N];
map<int,int> fqn[N];
int res[N];
int a[N]; 

void dfs(int node,int fa){
    fq[node][a[node]]=1;
    fqn[node][1]=1;
    for(int next:t[node]){
        if(next==fa) continue;
        dfs(next,node);
        if(fq[next].size()>fq[node].size()){
            swap(fq[next],fq[node]);
            swap(fqn[next],fqn[node]);
        }

        for(auto &[col,num]:fq[next]){
            while(num--){
                fq[node][col]++;
                fqn[node][fq[node][col]]++;
            }
        }

        fq[next].clear();
    }
    for(auto [limi,id]:ask[node]){
        res[id]=fqn[node][limi];
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

   
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    for(int i=0;i<m;i++){
        int node,num;
        cin>>node>>num;

        ask[node].emplace_back(num,i);
    }

    dfs(1,0);
    
    for(int i=0;i<m;i++){
        cout<<res[i]<<'\n';
    }


    //system("pause");
}
